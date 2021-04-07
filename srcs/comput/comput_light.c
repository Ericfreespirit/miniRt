/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comput_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 15:00:24 by eriling           #+#    #+#             */
/*   Updated: 2021/04/07 08:00:10 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"
#include "comput.h"
#include <mlx.h>
#include <math.h>

void	enlight_figure(t_vect origin, t_data *img, t_obj *light)
{
	double coeff;
	t_vect v_obj;
	v_obj = vect_obj(img->obj);
	
	coeff = dot(normalize(vect_sous(origin, v_obj)),
	normalize(vect_sous(vect_obj(light), origin)));
	if (coeff < 0)
		coeff = 0;
	coeff *= light->u.light.rat_l;
	img->total_light_coeff += coeff;
	img->total_light_color = sum_rgb(img->total_light_color, color_coeff(rgb_to_int(light), coeff));
}

void comput_all_light(t_data *img, t_vect origin)
{	
	size_t	i;
	t_vect		v_light;
	int			final_color;
	
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
