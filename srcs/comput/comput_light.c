/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comput_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 15:00:24 by eriling           #+#    #+#             */
/*   Updated: 2021/04/14 09:38:16 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"
#include "print_struct.h"
#include "comput.h"
#include <mlx.h>
#include <math.h>

t_vect vect_reverse(t_vect v)
{
	t_vect	res;

	res.x = v.x * -1;
	res.y = v.y * -1;
	res.z = v.z * -1;
	return (res);
}

t_vect get_normal(t_data *img, t_vect origin, t_vect dir)
{
	t_vect	v;

	v = init_vect(0, 0, 0);
	if (img->obj->my_type == sphere)
		v = normalize(vect_sous(origin, vect_obj(img->obj)));
	else if (img->obj->my_type == plane)
	{
		v = normalize(vect_orien_plane(img->obj));
		if (dot(dir, v) < 0)
			v = vect_reverse(v);
	}
	else if (img->obj->my_type == triangle)
	{
		v = normalize(get_normal_triangle(img->obj));
		if (dot(dir, v) < 0)
			v = vect_reverse(v);
	}
	else if (img->obj->my_type == square)
	{
		v = normalize(vect_orien_square(img->obj));
		if (dot(dir, v) < 0)
			v = vect_reverse(v);
	}
	return(v);
}

void	enlight_figure(t_vect origin, t_data *img, t_obj *light, t_vect dir)
{
	double	coeff;

	coeff = dot(normalize(get_normal(img, origin, dir)),
			normalize(vect_sous(vect_obj(light), origin)));
	if (coeff < 0)
		coeff = 0;
	coeff *= light->u.light.rat_l;
	img->total_light_coeff += coeff;
	img->total_light_color = sum_rgb(img->total_light_color,
			color_coeff(rgb_to_int(light), coeff));
}

void	comput_all_light(t_data *img, t_vect origin)
{	
	size_t	i;
	t_vect	v_light;
	int		final_color;

	img->total_light_coeff = 0;
	img->total_light_color = 0;
	i = 0;
	while (sg_dyn()->size > i)
	{
		if (sg_dyn()->obj[i]->my_type == light)
		{
			v_light = vect_obj(sg_dyn()->obj[i]);
			hit_light(ray_dir_obj(v_light, origin), origin,
					sg_dyn()->obj[i], img);
		}
		i++;
	}
	img->total_light_color = sum_rgb(img->total_light_color,
			color_coeff(rgb_to_int_ambiante(), singleton()->a_ran_light));
	final_color = mult_rgb(img->color, img->total_light_color);
	my_mlx_pixel_put(img, img->x, img->y, final_color);
}	
