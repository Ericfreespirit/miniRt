/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:07:16 by eriling           #+#    #+#             */
/*   Updated: 2021/03/25 10:02:22 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"
#include <mlx.h>
#include <math.h>

int check_hit_figure(t_vect *dir, t_obj *cam, double t, t_obj *obj)
{
	if (obj->my_type == sphere)
		if (hit_sphere(*dir, cam, *obj, &t) == 0)
			return (0);

	return (1);
}

void	hit_figure(t_data *img, t_vect *dir, t_obj *cam)
{
	size_t	i;
	double t;
	t_vect ray_inter;
	int hit;

	i = 0;
	t = DOUBLE_MAX;
	hit = 0;
	while (sg_dyn()->size > i)
	{
		if(check_hit_figure(dir, cam, t, sg_dyn()->obj[i]) == 0)
		{
			hit = 1;
			my_mlx_pixel_put(img, img->x, img->y, rgb_to_int(sg_dyn()->obj[i])); 
		}
		i++;
	}
	if (hit == 1)
		ray_inter = vect_sum(vect_origin(cam), scale(*dir, t));
}

void	ray(t_data *img, double pixel_len, t_obj *cam)
{
	t_vect	dir;
	double	norma;

	img->y = 0;
	while (img->y < singleton()->r_y)
	{
		img->x = 0;
		while (img->x < singleton()->r_x)
		{
			dir.x = (img->x - (singleton()->r_x / 2)) * pixel_len;
			dir.y = ((singleton()->r_y / 2) - img->y) * pixel_len;
			dir.z = 1;
			norma = sqrt(dir.x * dir.x + dir.y * dir.y + dir.z * dir.z);
			dir.x /= norma;
			dir.y /= norma;
			dir.z /= norma;
			hit_figure(img, &dir, cam);
			img->x++;
		}
		img->y++;
	}
}
