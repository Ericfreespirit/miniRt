/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comput_all_cam_view.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 09:04:33 by eriling           #+#    #+#             */
/*   Updated: 2021/04/03 14:43:29 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"
#include "comput.h"
#include <mlx.h>
#include <math.h>

void	comput_all_cam_view(t_data *img, t_vars *vars)
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
			ray(img, sg_dyn()->obj[i]);
		}
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, img->img, 0, 0);
}
