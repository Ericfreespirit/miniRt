/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 09:56:35 by eriling           #+#    #+#             */
/*   Updated: 2021/04/08 20:12:35 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "libft.h"
#include "parse.h"

int	check_data_in_cylinder(t_cy cylinder_data)
{
	int	i;

	i = 0;
	if (cylinder_data.orien_x >= -1 && cylinder_data.orien_x <= 1)
		i++;
	if (cylinder_data.orien_y >= -1 && cylinder_data.orien_y <= 1)
		i++;
	if (cylinder_data.orien_z >= -1 && cylinder_data.orien_z <= 1)
		i++;
	if (cylinder_data.r >= 0 && cylinder_data.r <= 255)
		i++;
	if (cylinder_data.g >= 0 && cylinder_data.g <= 255)
		i++;
	if (cylinder_data.b >= 0 && cylinder_data.b <= 255)
		i++;
	if (i < 6)
		return (1);
	return (0);
}

int	stock_cylinder(char **line, t_cy *cylinder_data)
{
	(*line)++;
	(*line)++;
	if (add_3_float(line, &(cylinder_data->x), &(cylinder_data->y),
			&(cylinder_data->z)) == 1)
		return (1);
	if (add_3_float(line, &(cylinder_data->orien_x), &(cylinder_data->orien_y),
			&(cylinder_data->orien_z)) == 1)
		return (1);
	cylinder_data->diam = ft_atof_2(line);
	cylinder_data->high = ft_atof_2(line);
	if (add_rgb(line, &(cylinder_data->r), &(cylinder_data->g),
			&(cylinder_data->b)) == 1)
		return (1);
	if (check_end_element(line) != 0)
		return (1);
	return (0);
}

int	parse_cylinder(char **line)
{
	t_obj	*obj;
	t_cy	*cylinder_data;
	int		range;

	range = sg_dyn()->size;
	obj = malloc(sizeof(t_obj));
	if (obj == NULL)
		return (1);
	dynarr_push(sg_dyn(), obj); // Push object in dynamic array
	sg_dyn()->obj[range]->my_type = cylinder; // Assign type for object
	cylinder_data = &(sg_dyn()->obj[range]->u.cylinder);
	if (stock_cylinder(line, cylinder_data) == 0)
		if (check_data_in_cylinder(*cylinder_data) == 0)
			return (0);
	return (1);
}
