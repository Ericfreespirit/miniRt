/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 09:56:49 by eriling           #+#    #+#             */
/*   Updated: 2021/04/08 20:11:27 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "libft.h"
#include "parse.h"

int	check_data_in_light(t_l light_data)
{
	int	i;

	i = 0;
	if (light_data.rat_l >= -1 && light_data.rat_l <= 1)
		i++;
	if (light_data.r >= 0 && light_data.r <= 255)
		i++;
	if (light_data.g >= 0 && light_data.g <= 255)
		i++;
	if (light_data.b >= 0 && light_data.b <= 255)
		i++;
	if (i < 4)
		return (1);
	return (0);
}

int	stock_light(char **line, t_l *light_data)
{
	(*line)++;
	if (add_3_float(line, &(light_data->x), &(light_data->y),
			&(light_data->z)) == 1)
		return (1);
	light_data->rat_l = ft_atof_2(line);
	if (add_rgb(line, &(light_data->r), &(light_data->g),
			&(light_data->b)) == 1)
		return (1);
	if (check_end_element(line) != 0)
		return (1);
	return (0);
}

int	parse_light(char **line)
{
	t_obj	*obj;
	t_l		*light_data;
	int		range;

	range = sg_dyn()->size;
	obj = malloc(sizeof(t_obj));
	if (obj == NULL)
		return (1);
	dynarr_push(sg_dyn(), obj); // Push object in dynamic array
	sg_dyn()->obj[range]->my_type = light; // Assign type for object
	light_data = &(sg_dyn()->obj[range]->u.light);
	if (stock_light(line, light_data) == 0)
		if (check_data_in_light(*light_data) == 0)
			return (0);
	return (1);
}
