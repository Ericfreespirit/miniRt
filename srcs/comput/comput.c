/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comput.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 09:04:33 by eriling           #+#    #+#             */
/*   Updated: 2021/03/29 18:25:49 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"
#include <mlx.h>
#include <math.h>



void add_ambiante(t_data *img)
{
	int color;
	double r = (double)(singleton()->a_r / 255);
	double g = (double)(singleton()->a_g / 255);
	double b = (double)(singleton()->a_b / 255);
	
	r *= singleton()->a_ran_light;
	g *= singleton()->a_ran_light;
	b *= singleton()->a_ran_light;

	r = fmin(r, 1.0);
	g = fmin(g, 1.0);
	b = fmin(b, 1.0);

	r *= 255.;
	g *= 255.;
	b *= 255.;
	
	int r_int = (int)round(r);
	int g_int = (int)round(g);
	int b_int = (int)round(b);

	color = 65536 * r_int + 256 * g_int + b_int;
	img->y = 0;
	while (img->y < singleton()->r_y)
	{
		img->x = 0;
		while (img->x < singleton()->r_x)
		{
			my_mlx_pixel_put(img, img->x, img->y, color);
			img->x++;
		}
		img->y++;
	}
}

int	all_cam_view(t_data *img)
{
	double	vp_width;
	double	vp_height;
	double	ratio;
	size_t	i;

	i = 0;
	ratio = (double)singleton()->r_y / (double)singleton()->r_x;
	add_ambiante(img);
	while (sg_dyn()->size > i)
	{
		if (sg_dyn()->obj[i]->my_type == camera)
		{
			vp_width = ft_abs(tan((sg_dyn()->obj[i]->u.camera.fov / 2.0)
						/ 57.29)) * 2;
			vp_height = vp_width * ratio;
			img->pixel_len = vp_width / (double)singleton()->r_x;
			ray(img, img->pixel_len, sg_dyn()->obj[i]);
		}
		i++;
	}
	return (0);
}

void	comput(t_data *img, t_vars *vars)
{
	if (all_cam_view(img) == 1)
		printf("Error: all_cam_view()");
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, img->img, 0, 0);
}
