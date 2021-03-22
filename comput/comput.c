/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comput.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 09:04:33 by eriling           #+#    #+#             */
/*   Updated: 2021/03/22 08:58:21 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"
#include <mlx.h>
#include <math.h>

double	dot(t_vect v1, t_vect v2)
{
	double	res;

	res = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (res);
}
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	hit_sphere(t_vect dir, t_obj *cam, t_obj *sp)
{
	t_vect	v_cam;
	double	a;
	double	b;
	double	c;
	double	discriminant;

	v_cam.x = cam->u.camera.x - sp->u.sphere.x;
	v_cam.y = cam->u.camera.y - sp->u.sphere.y;
	v_cam.z = cam->u.camera.z - sp->u.sphere.z;
	a = 1;
	b = 2.0 * dot(v_cam, dir);
	c = dot(v_cam, v_cam) - (sp->u.sphere.diam / 2) * (sp->u.sphere.diam / 2);
	discriminant = b * b - 4 * a * c;
	if (discriminant > 0)
		return (1);
	return (0);
}

int	rgb_to_int(t_obj *obj)
{
	int	r;
	int g;
	int b;
	int color;

	r = obj->u.sphere.r;
	g = obj->u.sphere.g;
	b = obj->u.sphere.b;
	color = 65536 * r + 256 * g + b;
	return (color);
}

int hit_figure(t_data *img, t_vect *dir, t_obj *cam, int x, int y)
{
	size_t i;

	i = 0;
	while (sg_dyn()->size > i)
	{
		if (sg_dyn()->obj[i]->my_type == sphere)
			if (hit_sphere(*dir, cam, sg_dyn()->obj[i]) == 1)
				my_mlx_pixel_put(img, x, y, rgb_to_int(sg_dyn()->obj[i]));
		i++;
	}
	return(0);
}

void	ray(t_data *img, double pixel_len, t_obj *cam)
{
	t_vect	dir;
	double	norma;
	int		x;
	int		y;

	y = 0;
	while (y < singleton()->r_y)
	{
		x = 0 ;
		while (x < singleton()->r_x)
		{
			dir.x = (x - (singleton()->r_x / 2)) * pixel_len;
			dir.y = ((singleton()->r_y / 2) - y) * pixel_len;
			dir.z = 1;
			norma = sqrt(dir.x * dir.x + dir.y * dir.y + dir.z * dir.z);
			dir.x /= norma;
			dir.y /= norma;
			dir.z /= norma;
			hit_figure(img, &dir, cam, x , y);
			x++;
		}
		y++;
	}
}

int all_cam_view(t_data *img, t_vars *vars)
{
	double	vp_width;
	double	vp_height;
	double	ratio;
	double	pixel_len;
	size_t	i;

	i = 0;
	ratio = (double)singleton()->r_y / (double)singleton()->r_x;
	while (sg_dyn()->size > i)
	{
		if (sg_dyn()->obj[i]->my_type == camera)
		{
			vp_width = ft_abs(tan((sg_dyn()->obj[i]->u.camera.fov / 2.0) / 57.29)) * 2;
			vp_height = vp_width * ratio;
			pixel_len = vp_width / (double)singleton()->r_x;
			img->img = mlx_new_image(vars->mlx, singleton()->r_x, singleton()->r_y);
			img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
					&img->line_length, &img->endian);
			ray(img, pixel_len, sg_dyn()->obj[i]);
        		}
		i++;
	}
	return(0);
}

void	comput(t_data *img, t_vars *vars)
{
	if (all_cam_view(img, vars) == 1)
		printf("Error: all_cam_view()");
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, img->img, 0, 0);
	// save image
}
