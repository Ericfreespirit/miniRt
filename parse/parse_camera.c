/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 09:56:23 by eriling           #+#    #+#             */
/*   Updated: 2021/02/18 16:29:15 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	check_data_in_camera(t_c camera_data)
{
	int	i;

	i = 0;
	if (camera_data.vect_x >= -1 && camera_data.vect_x <= 1)
		i++;
	if (camera_data.vect_y >= -1 && camera_data.vect_y <= 1)
		i++;
	if (camera_data.vect_z >= -1 && camera_data.vect_z <= 1)
		i++;
	if (camera_data.fov >= 0 && camera_data.fov <= 180)
		i++;
	if (i < 4)
		return (1);
	return (0);
}

int	stock_camera(char **line, t_c *camera_data)
{
	(*line)++;
	if (add_3_float(line, &(camera_data->x), &(camera_data->y),
			&(camera_data->z)) == 1)
		return (1);
	if (add_3_float(line, &(camera_data->vect_x), &(camera_data->vect_y),
			&(camera_data->vect_z)) == 1)
		return (1);
	camera_data->fov = ft_atoi_2(line);
	if (**line != 0)
		return (1);
	return (0);
}

int	parse_camera(char **line)
{
	t_obj	*obj;
	t_c		*camera_data;
	int		range;

	range = sg_dyn()->size;
	obj = malloc(sizeof(t_obj));
	if (obj == NULL)
		return (1);
	dynarr_push(sg_dyn(), obj); // Push object in dynamic array
	sg_dyn()->obj[range]->my_type = camera; // Assign type for object
	camera_data = &(sg_dyn()->obj[range]->u.camera);
	if (stock_camera(line, camera_data) == 0)
		if (check_data_in_camera(*camera_data) == 0)
			return (0);
	return (1);
}
