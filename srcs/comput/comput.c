/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comput.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 09:04:33 by eriling           #+#    #+#             */
/*   Updated: 2021/03/30 09:47:32 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"
#include <mlx.h>
#include <math.h>

int brightness_coeff(int color, double coeff)
{
	int r;
	int g;
	int b;

	r = (color >> 16) & 0b11111111;
	g = (color >> 8) & 0b11111111;
	b = (color >> 0) & 0b11111111;
	r *= coeff;
	g *= coeff;
	b *= coeff;
	color = (r << 16) + (g << 8) + (b << 0);
	return(color);
}

void add_ambiante(t_data *img)
{
	int color;
	int rgb;

	rgb = (singleton()->a_r << 16) + (singleton()->a_g << 8) + (singleton()->a_b << 0);
	color = brightness_coeff(rgb, singleton()->a_ran_light);
	my_mlx_pixel_put(img, img->x, img->y, color);
}

int	all_cam_view(t_data *img)
{
	double	vp_width;
	double	vp_height;
	double	ratio;
	size_t	i;

	i = 0;
	ratio = (double)singleton()->r_y / (double)singleton()->r_x;
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
