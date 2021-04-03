/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 09:57:22 by eriling           #+#    #+#             */
/*   Updated: 2021/04/03 13:55:09 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "libft.h"
#include "parse.h"

int	check_data_in_sphere(t_sp sphere_data)
{
	int	i;

	i = 0;
	if (sphere_data.r >= 0 && sphere_data.r <= 255)
		i++;
	if (sphere_data.g >= 0 && sphere_data.g <= 255)
		i++;
	if (sphere_data.b >= 0 && sphere_data.b <= 255)
		i++;
	if (i < 3)
		return (1);
	return (0);
}

int	stock_sphere(char **line, t_sp *sphere_data)
{
	(*line)++;
	(*line)++;
	if (add_3_float(line, &(sphere_data->x), &(sphere_data->y),
			&(sphere_data->z)) == 1)
		return (1);
	sphere_data->diam = ft_atof_2(line);
	if (add_rgb(line, &(sphere_data->r), &(sphere_data->g),
			&(sphere_data->b)) == 1)
		return (1);
	if (**line != 0)
		return (1);
	return (0);
}

int	parse_sphere(char **line)
{
	t_obj	*obj;
	t_sp	*sphere_data;
	int		range;

	range = sg_dyn()->size;
	obj = malloc(sizeof(t_obj));
	if (obj == NULL)
		return (1);
	dynarr_push(sg_dyn(), obj); // Push object in dynamic array
	sg_dyn()->obj[range]->my_type = sphere; // Assign type for object
	sphere_data = &(sg_dyn()->obj[range]->u.sphere);
	if (stock_sphere(line, sphere_data) == 0)
		if (check_data_in_sphere(*sphere_data) == 0)
			return (0);
	return (1);
}
