/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:07:16 by eriling           #+#    #+#             */
/*   Updated: 2021/04/07 11:48:49 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"
#include "comput.h"
#include <mlx.h>
#include <math.h>

int	check_hit_figure(t_vect dir, t_vect origin, t_data *img, t_obj *obj)
{
	if (obj->my_type == sphere)
	{
		if (hit_sphere(dir, origin, img, obj) == 1)
			return (1);
	}
	else if (obj->my_type == plane)
	{
		if ((hit_plane(dir, origin, img, obj) == 1))
		{
			return (1);
		}
	}
	return (0);
}

void	hit_light(t_vect dir, t_vect origin, t_obj *light, t_data *img)
{
	size_t	i;
	t_data	fig_to_light;
	int		hit;

	i = 0;
	fig_to_light.t = DOUBLE_MAX;
	hit = 0;
	while (sg_dyn()->size > i)
	{
		if (i != (size_t)img->id_obj)
			if (check_hit_figure(dir, origin, &fig_to_light,
					sg_dyn()->obj[i]) == 1)
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
		comput_all_light(img, vect_sum(origin, scale(dir, img->t)));
}

void	ray(t_data *img, t_obj *cam)
{
	t_matr	matrix;
	t_vect	dir_cam;
	t_vect	orien_cam;
	t_vect	rot_axis;
	double	angle;

	orien_cam = vect_orien_cam(cam);
	rot_axis = cross_prod(init_vect(0, 0, 1), normalize(vect_orien_cam(cam)));
	angle = find_angle(normalize(vect_orien_cam(cam)), init_vect(0, 0, 1));
	img->y = 0;
	while (img->y < singleton()->r_y)
	{
		img->x = 0;
		while (img->x < singleton()->r_x)
		{
			matrix = orien_matrix(normalize(rot_axis), angle);
			dir_cam = ray_dir_cam(*img);
			if (!(orien_cam.x == 0 && orien_cam.y == 0 && orien_cam.z == 1))
				dir_cam = comput_orien_matrix(matrix, dir_cam);
			hit_figure(img, dir_cam, vect_obj(cam));
			img->x++;
		}
		img->y++;
	}
}
