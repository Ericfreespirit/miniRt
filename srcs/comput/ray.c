/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:07:16 by eriling           #+#    #+#             */
/*   Updated: 2021/03/31 14:51:31 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"
#include <mlx.h>
#include <math.h>

int check_hit_figure(t_vect dir, t_vect origin, t_data *img, t_obj *obj)
{
	if (obj->my_type == sphere)
		if (hit_sphere(dir, origin, img, obj) == 1)
			return (1);
	return (0);
}


int		color_final(double coeff_light, int color_obj, int color_light)
{
	int final_color;
	int color_light_total;
	double coeff_total;

	coeff_total = coeff_light + singleton()->a_ran_light;
	color_light_total = mix_rgb(color_light,rgb_to_int_ambiante(), coeff_light / coeff_total);
	if (coeff_total > 1)
		coeff_total = 1;
	final_color = mix_rgb(color_light_total, color_obj, 0.5);
	final_color = brightness_coeff(final_color, coeff_total);
	return (final_color);
}

void	hit_light(t_vect dir, t_vect origin, t_obj *light, t_data *img)
{
	size_t	i;
	t_data fig_to_light;
	int hit;
	double coeff;
	t_vect v_obj;

	i = 0;
	fig_to_light.t = DOUBLE_MAX;
	hit = 0;
	v_obj = vect_obj(img->obj);
	while (sg_dyn()->size > i)
	{
		if (i != img->id_obj)
			if(check_hit_figure(dir, origin, &fig_to_light, sg_dyn()->obj[i]) == 1)
				hit = 1;
		i++;
	}
	if (hit == 0)
	{
		coeff = dot(normalize(vect_distance(origin, v_obj)),normalize(vect_distance(vect_obj(light), origin)));
		if (coeff < 0)
			coeff = 0;
		coeff *= light->u.light.rat_l;
		img->total_light_coeff += coeff;
		img->total_light_color = sum_rgb(img->total_light_color, brightness_coeff(rgb_to_int(light), coeff));
		return ;
	}
}

void	hit_figure(t_data *img, t_vect dir, t_vect origin)
{
	size_t		i;
	int			hit;
	int			final_color;
	t_vect		v_light;

	i = 0;
	img->t = DOUBLE_MAX;
	hit = 0;
	img->total_light_coeff = 0;
	img->total_light_color = 0;
	while (sg_dyn()->size > i)
	{
		if (check_hit_figure(dir, origin, img, sg_dyn()->obj[i]) == 1)
		{
			img->id_obj = i;
			hit = 1;
		}
		i++;
	}
	if (hit == 1)
	{
		i = 0;
		while (sg_dyn()->size > i)
		{
			if (sg_dyn()->obj[i]->my_type == light)
			{
				v_light = vect_obj(sg_dyn()->obj[i]);
				 hit_light(ray_dir_obj(v_light, origin),vect_sum(origin, scale(dir, img->t)), 
				 sg_dyn()->obj[i], img);
			}
			i++;
		}
		img->total_light_coeff += singleton()->a_ran_light;
		img->total_light_color = sum_rgb(img->total_light_color, brightness_coeff(rgb_to_int_ambiante(), singleton()->a_ran_light));
		final_color = brightness_coeff(img->color, img->total_light_coeff);
		final_color = mix_rgb(img->total_light_color, final_color, img->total_light_coeff);
		my_mlx_pixel_put(img, img->x, img->y, final_color);
	}	
}

t_vect ray_dir_obj(t_vect v1, t_vect v2)
{
	t_vect dir;
	
	dir = vect_distance(v1, v2);
	return (normalize(dir));
}

t_vect ray_dir_cam(t_data img)
{
	t_vect dir;
	
	dir.x = (img.x - (singleton()->r_x / 2)) * img.pixel_len;
	dir.y = ((singleton()->r_y / 2) - img.y) * img.pixel_len;
	dir.z = 1;
	return (normalize(dir));
}

void	ray(t_data *img, t_obj *cam)
{
	t_vect	dir;

	img->y = 0;
	while (img->y < singleton()->r_y)
	{
		img->x = 0;
		while (img->x < singleton()->r_x)
		{
			dir = ray_dir_cam(*img);
			hit_figure(img, dir, vect_obj(cam));		
			img->x++;
		}
		img->y++;
	}
}
