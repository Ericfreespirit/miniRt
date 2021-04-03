/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_triangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 09:57:42 by eriling           #+#    #+#             */
/*   Updated: 2021/04/03 13:55:07 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "parse.h"

int	check_data_in_triangle(t_tr triangle_data)
{
	int	i;

	i = 0;
	if (triangle_data.r >= 0 && triangle_data.r <= 255)
		i++;
	if (triangle_data.g >= 0 && triangle_data.g <= 255)
		i++;
	if (triangle_data.b >= 0 && triangle_data.b <= 255)
		i++;
	if (i < 3)
		return (1);
	return (0);
}

int	stock_triangle(char **line, t_tr *triangle_data)
{
	(*line)++;
	(*line)++;
	if (add_3_float(line, &(triangle_data->x_1), &(triangle_data->y_1),
			&(triangle_data->z_1)) == 1)
		return (1);
	if (add_3_float(line, &(triangle_data->x_2), &(triangle_data->y_2),
			&(triangle_data->z_2)) == 1)
		return (1);
	if (add_3_float(line, &(triangle_data->x_3), &(triangle_data->y_3),
			&(triangle_data->z_3)) == 1)
		return (1);
	if (add_rgb(line, &(triangle_data->r), &(triangle_data->g),
			&(triangle_data->b)) == 1)
		return (1);
	if (**line != 0)
		return (1);
	return (0);
}

int	parse_triangle(char **line)
{
	t_obj	*obj;
	t_tr	*triangle_data;
	int		range;

	range = sg_dyn()->size;
	obj = malloc(sizeof(t_obj));
	if (obj == NULL)
		return (1);
	dynarr_push(sg_dyn(), obj); // Push object in dynamic array
	sg_dyn()->obj[range]->my_type = triangle; // Assign type for object
	triangle_data = &(sg_dyn()->obj[range]->u.triangle);
	if (stock_triangle(line, triangle_data) == 0)
		if (check_data_in_triangle(*triangle_data) == 0)
			return (0);
	return (1);
}
