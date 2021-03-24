/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:07:16 by eriling           #+#    #+#             */
/*   Updated: 2021/03/24 15:04:53 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"
#include <mlx.h>
#include <math.h>

void dir_origin(t_vect *dir, t_vect *origin, t_obj *cam, double t)
{
	dir-> x *= t;
	dir-> y *= t;
	dir-> z *= t;
	origin->x = cam->u.camera.x;
	origin->y = cam->u.camera.y;
	origin->z = cam->u.camera.z;
}

int	hit_figure(t_data *img, t_vect *dir, t_obj *cam)
{
	size_t	i;
	double t;
	t_vect inter;
	t_vect origin;

	i = 0;
	t = DOUBLE_MAX;
	while (sg_dyn()->size > i)
	{
		if (sg_dyn()->obj[i]->my_type == sphere)
			if (hit_sphere(*dir, cam, sg_dyn()->obj[i], &t) == 0)
				my_mlx_pixel_put(img, img->x, img->y, rgb_to_int(sg_dyn()->obj[i])); // at the end

		
		i++;
	}
	dir_origin(dir, &origin, cam, t);
	inter = vect_sum(origin, *dir);
	return (0);
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
