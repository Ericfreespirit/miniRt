/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comput_all_cam_view.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 09:04:33 by eriling           #+#    #+#             */
/*   Updated: 2021/04/27 10:46:52 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"
#include "comput.h"
#include "print_struct.h"
#include <mlx.h>
#include <math.h>

size_t count_cam(void)
{
	size_t	i;
	size_t count;

	i = 0;
	count = 0;
	while (sg_dyn()->size > i)
	{
		if (sg_dyn()->obj[i]->my_type == camera)
			count++;
		i++;
	}
	return (count);
}

t_scene *comput_all_cam_view(t_vars *vars)
{
	t_viewplane vpl;
	size_t	i;
	size_t	j;
	t_scene	*array;

	i = 0;
	j = 0;
	vpl.ratio = (double)singleton()->r_y / (double)singleton()->r_x;
	array = malloc (sizeof(t_scene) * count_cam());
	if (array == NULL)
		return (array);
	while (sg_dyn()->size > i)
	{
		if (sg_dyn()->obj[i]->my_type == camera)
		{
			vpl.vp_width = ft_abs(tan((sg_dyn()->obj[i]->u.camera.fov / 2.0)
						/ 57.29)) * 2;
			vpl.vp_height = vpl.vp_width * vpl.ratio;
			array[j].img_scene.img = mlx_new_image(vars->mlx, singleton()->r_x, singleton()->r_y);
			array[j].img_scene.addr = mlx_get_data_addr(array[j].img_scene.img, &array[j].img_scene.bits_per_pixel,
			&array[j].img_scene.line_length, &array[j].img_scene.endian);
			
			array[j].img_scene.pixel_len = vpl.vp_width / (double)singleton()->r_x;
			array[j].img_scene.cam = sg_dyn()->obj[i];
			ray(&array[j].img_scene, sg_dyn()->obj[i]);
			j++;
		}
		i++;
	}
	return (array);
}
