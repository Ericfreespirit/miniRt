/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:07:16 by eriling           #+#    #+#             */
/*   Updated: 2021/03/26 09:25:10 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"
#include <mlx.h>
#include <math.h>

int check_hit_figure(t_vect *dir, t_obj *cam, t_data *img, t_obj *obj)
{
	if (obj->my_type == sphere)
		if (hit_sphere(*dir, cam, *obj, img) == 1)
			return (1);
	return (0);
}

void	hit_light(t_vect dir, t_vect origin, t_l light, t_data *img)
{
	size_t	i;
	t_last_hit from_inter;
	int hit;
	double angle;

	i = 0;
	from_inter.t = DOUBLE_MAX;
	hit = 0;
	while (sg_dyn()->size > i)
	{
		if(check_hit_figure(&dir, &origin, &from_inter, sg_dyn()->obj[i]) == 0)
			hit = 1;
		i++;
	}
	if (hit == 0)
	{
		angle = cos(dot(origin, vect_light(light)));
		//final_color();
		//my_mlx_pixel_put(t_data *data, int x, int y, int color);
	}
	//display ambiante
}

void add_ambiante(t_data *img)
{
	// 1. search type of obj
	// 2. put obj color in img color
}

void	hit_figure(t_data *img, t_vect *dir, t_obj *cam)
{
	size_t		i;
	int			hit;

	i = 0;
	img->t = DOUBLE_MAX;
	hit = 0;
	while (sg_dyn()->size > i)
	{
		if (check_hit_figure(dir, cam, img, sg_dyn()->obj[i]) == 1)
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
					vect_sum(vect_origin(cam), scale(*dir, img->t)), 
					sg_dyn()->obj[i]->u.light, img);
			i++;
		}
	}
	add_ambiante(img);
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
			hit_figure(&img, &dir, cam);
			img->x++;
		}
		img->y++;
	}
}
