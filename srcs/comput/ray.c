/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:07:16 by eriling           #+#    #+#             */
/*   Updated: 2021/03/25 18:20:04 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"
#include <mlx.h>
#include <math.h>

int check_hit_figure(t_vect *dir, t_obj *cam, t_last_hit *lh, t_obj *obj)
{
	if (obj->my_type == sphere)
		if (hit_sphere(*dir, cam, *obj, lh) == 1)
			return (1);
	return (0);
}

void	hit_light(t_vect dir, t_vect origin, t_l light)
{
	size_t	i;
	t_vect vect_l;
	double t;
	int hit;
	double angle;

	i = 0;
	t = DOUBLE_MAX;
	hit = 0;
	while (sg_dyn()->size > i)
	{
		if(check_hit_figure(&dir, &origin, &t, sg_dyn()->obj[i]) == 0)
			hit = 1;
		i++;
	}
	if (hit == 0)
	{
		angle = cos(dot(origin, vect_light(light)));
		//final_color();
	}
	//display ambiante
}

void	hit_figure(t_data *img, t_vect *dir, t_obj *cam)
{
	size_t		i;
	t_last_hit	lh;
	int			hit;

	i = 0;
	lh.t = DOUBLE_MAX;
	hit = 0;
	while (sg_dyn()->size > i)
	{
		if (check_hit_figure(dir, cam, &lh, sg_dyn()->obj[i]) == 1)
			hit = 1;
		i++;
	}
	if (hit == 1)
	{
		i = 0;
		while (sg_dyn()->size > i)
		{
			if (sg_dyn()->obj[i]->my_type == light)
				hit_light(normal(img->x, img->y, img->pixel_len), 
					vect_sum(vect_origin(cam), scale(*dir, lh.t)), sg_dyn()->obj[i]->u.light);
			i++;
		}
	}
	// display lumiere ambiante	
}

t_vect normal(int x, int y, double pixel_len)
{
	t_vect dir;
	double norma;
	
	dir.x = (x - (singleton()->r_x / 2)) * pixel_len;
	dir.y = ((singleton()->r_y / 2) - y) * pixel_len;
	dir.z = 1;
	norma = sqrt(dot(dir, dir));
	dir.x /= norma;
	dir.y /= norma;
	dir.z /= norma;	

	return (dir);
}

void	ray(t_data *img, double pixel_len, t_obj *cam)
{
	t_vect	dir;

	img->y = 0;
	while (img->y < singleton()->r_y)
	{
		img->x = 0;
		while (img->x < singleton()->r_x)
		{
			dir = normal(img->x, img->y, pixel_len);
			hit_figure(img, &dir, cam);
			img->x++;
		}
		img->y++;
	}
}
