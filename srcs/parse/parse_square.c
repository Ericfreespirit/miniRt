/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 09:57:30 by eriling           #+#    #+#             */
/*   Updated: 2021/04/08 20:12:29 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "libft.h"
#include "parse.h"

int	check_data_in_square(t_sq square_data)
{
	int	i;

	i = 0;
	if (square_data.orien_x >= -1 && square_data.orien_x <= 1)
		i++;
	if (square_data.orien_y >= -1 && square_data.orien_y <= 1)
		i++;
	if (square_data.orien_z >= -1 && square_data.orien_z <= 1)
		i++;
	if (square_data.r >= 0 && square_data.r <= 255)
		i++;
	if (square_data.g >= 0 && square_data.g <= 255)
		i++;
	if (square_data.b >= 0 && square_data.b <= 255)
		i++;
	if (i < 6)
		return (1);
	return (0);
}

int	stock_square(char **line, t_sq *square_data)
{
	(*line)++;
	(*line)++;
	if (add_3_float(line, &(square_data->x), &(square_data->y),
			&(square_data->z)) == 1)
		return (1);
	if (add_3_float(line, &(square_data->orien_x), &(square_data->orien_y),
			&(square_data->orien_z)) == 1)
		return (1);
	square_data->high = ft_atof_2(line);
	if (add_rgb(line, &(square_data->r), &(square_data->g),
			&(square_data->b)) == 1)
		return (1);
	if (check_end_element(line) != 0)
		return (1);
	return (0);
}

int	parse_square(char **line)
{
	t_obj	*obj;
	t_sq	*square_data;
	int		range;

	range = sg_dyn()->size;
	obj = malloc(sizeof(t_obj));
	if (obj == NULL)
		return (1);
	dynarr_push(sg_dyn(), obj); // Push object in dynamic array
	sg_dyn()->obj[range]->my_type = square; // Assign type for object
	square_data = &(sg_dyn()->obj[range]->u.square);
	if (stock_square(line, square_data) == 0)
		if (check_data_in_square(*square_data) == 0)
			return (0);
	return (1);
}
