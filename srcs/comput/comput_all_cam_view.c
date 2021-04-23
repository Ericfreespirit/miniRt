/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comput_all_cam_view.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 09:04:33 by eriling           #+#    #+#             */
/*   Updated: 2021/04/23 20:23:04 by eriling          ###   ########.fr       */
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

t_scene *comput_all_cam_view(t_data *img)
{
	t_viewplane vpl;
	size_t	i;
	size_t	j;
	t_scene	*array = NULL;

	i = 0;
	j = 0;
	vpl.ratio = (double)singleton()->r_y / (double)singleton()->r_x;
	array = malloc(sizeof(t_scene *));
	array->img_scene = malloc (sizeof(t_scene *) * count_cam());
	while (sg_dyn()->size > i)
	{
		if (sg_dyn()->obj[i]->my_type == camera)
		{
			vpl.vp_width = ft_abs(tan((sg_dyn()->obj[i]->u.camera.fov / 2.0)
						/ 57.29)) * 2;
			vpl.vp_height = vpl.vp_width * vpl.ratio;

			// init img;
			vars.img.img = mlx_new_image(vars.mlx, singleton()->r_x, singleton()->r_y);
			vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel,
				&vars.img.line_length, &vars.img.endian);

			img->pixel_len = vpl.vp_width / (double)singleton()->r_x;
			img->cam = sg_dyn()->obj[i];
			ray(img, sg_dyn()->obj[i]);
			array->img_scene[j++] = img;
		}
		i++;
	}
	return (array);
}
