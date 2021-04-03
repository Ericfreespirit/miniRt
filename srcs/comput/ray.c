/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:07:16 by eriling           #+#    #+#             */
/*   Updated: 2021/04/03 15:26:11 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"
#include "comput.h"
#include <mlx.h>
#include <math.h>

int check_hit_figure(t_vect dir, t_vect origin, t_data *img, t_obj *obj)
{
	if (obj->my_type == sphere)
		if (hit_sphere(dir, origin, img, obj) == 1)
			return (1);
	return (0);
}

void	hit_light(t_vect dir, t_vect origin, t_obj *light, t_data *img)
{
	size_t	i;
	t_data fig_to_light;
	int hit;

	i = 0;
	fig_to_light.t = DOUBLE_MAX;
	hit = 0;
	while (sg_dyn()->size > i)
	{
		if (i != (size_t)img->id_obj)
			if(check_hit_figure(dir, origin, &fig_to_light, sg_dyn()->obj[i]) == 1)
				hit = 1;
		i++;
	}
	if (hit == 0)
		enlight_figure(origin, img, light);
}

void	hit_figure(t_data *img, t_vect dir, t_vect origin)
{
	size_t		i;
	int			hit;

	i = 0;
	img->t = DOUBLE_MAX;
	hit = 0;
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
		comput_all_light(img, dir, origin);
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
