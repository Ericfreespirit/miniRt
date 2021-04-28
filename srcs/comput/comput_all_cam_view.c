/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comput_all_cam_view.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 09:04:33 by eriling           #+#    #+#             */
/*   Updated: 2021/04/28 10:25:09 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"
#include "comput.h"
#include "print_struct.h"
#include <mlx.h>
#include <math.h>

size_t	count_cam(void)
{
	size_t	i;
	size_t	count;

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

void	init_comput_all_cam_view_var(t_viewplane *vpl)
{
	vpl->i = 0;
	vpl->j = 0;
	vpl->ratio = (double)singleton()->r_y / (double)singleton()->r_x;
}

void	create_scene(t_viewplane *vpl, t_scene *array, t_vars *vars)
{
	vpl->vp_width = ft_abs(tan((sg_dyn()->obj[vpl->i]->u.camera.fov / 2.0)
				/ 57.29)) * 2;
	vpl->vp_height = vpl->vp_width * vpl->ratio;
	array[vpl->j].img_scene.img = mlx_new_image(vars->mlx,
			singleton()->r_x, singleton()->r_y);
	array[vpl->j].img_scene.addr = mlx_get_data_addr(
			array[vpl->j].img_scene.img,
			&array[vpl->j].img_scene.bits_per_pixel,
			&array[vpl->j].img_scene.line_length,
			&array[vpl->j].img_scene.endian);
	array[vpl->j].img_scene.pixel_len = vpl->vp_width
		/ (double)singleton()->r_x;
	array[vpl->j].img_scene.cam = sg_dyn()->obj[vpl->i];
	ray(&array[vpl->j].img_scene, sg_dyn()->obj[vpl->i]);
}

t_scene	*comput_all_cam_view(t_vars *vars)
{
	t_viewplane	vpl;
	t_scene		*array;

	init_comput_all_cam_view_var(&vpl);
	array = malloc (sizeof(t_scene) * count_cam());
	if (array == NULL)
		return (array);
	while (sg_dyn()->size > vpl.i)
	{
		if (sg_dyn()->obj[vpl.i]->my_type == camera)
		{
			create_scene(&vpl, array, vars);
			vpl.j++;
		}
		vpl.i++;
	}
	return (array);
}
