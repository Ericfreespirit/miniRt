/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 09:57:03 by eriling           #+#    #+#             */
/*   Updated: 2021/04/08 20:12:22 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "parse.h"

int	check_data_in_plane(t_pl plane_data)
{
	int	i;

	i = 0;
	if (plane_data.orien_x >= -1 && plane_data.orien_x <= 1)
		i++;
	if (plane_data.orien_y >= -1 && plane_data.orien_y <= 1)
		i++;
	if (plane_data.orien_z >= -1 && plane_data.orien_z <= 1)
		i++;
	if (plane_data.r >= 0 && plane_data.r <= 255)
		i++;
	if (plane_data.g >= 0 && plane_data.g <= 255)
		i++;
	if (plane_data.b >= 0 && plane_data.b <= 255)
		i++;
	if (i < 6)
		return (1);
	return (0);
}

int	stock_plane(char **line, t_pl *plane_data)
{
	(*line)++;
	(*line)++;
	if (add_3_float(line, &(plane_data->x), &(plane_data->y),
			&(plane_data->z)) == 1)
		return (1);
	if (add_3_float(line, &(plane_data->orien_x), &(plane_data->orien_y),
			&(plane_data->orien_z)) == 1)
		return (1);
	if (add_rgb(line, &(plane_data->r), &(plane_data->g),
			&(plane_data->b)) == 1)
		return (1);
	if (check_end_element(line) != 0)
		return (1);
	return (0);
}

int	parse_plane(char **line)
{
	t_obj	*obj;
	t_pl	*plane_data;
	int		range;

	range = sg_dyn()->size;
	obj = malloc(sizeof(t_obj));
	if (obj == NULL)
		return (1);
	dynarr_push(sg_dyn(), obj); // Push object in dynamic array
	sg_dyn()->obj[range]->my_type = plane; // Assign type for object
	plane_data = &(sg_dyn()->obj[range]->u.plane);
	if (stock_plane(line, plane_data) == 0)
		if (check_data_in_plane(*plane_data) == 0)
			return (0);
	return (1);
}
