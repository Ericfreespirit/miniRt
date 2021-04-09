/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 09:55:36 by eriling           #+#    #+#             */
/*   Updated: 2021/04/08 20:09:56 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"
#include "libft.h"
#include "parse.h"

int	check_data_in_ambient(void)
{
	int	i;

	i = 0;
	if (singleton()->a_ran_light >= 0.0 && singleton()->a_ran_light <= 1.0)
		i++;
	if (singleton()->a_r >= 0 && singleton()->a_r <= 255)
		i++;
	if (singleton()->a_g >= 0 && singleton()->a_g <= 255)
		i++;
	if (singleton()->a_b >= 0 && singleton()->a_b <= 255)
		i++;
	if (i < 4)
		return (1);
	return (0);
}

int	parse_ambient(char **line)
{
	if (singleton()->a == 1)
		return (1);
	singleton()->a = 1;
	(*line)++;
	singleton()->a_ran_light = ft_atof_2(line);
	if (add_rgb(line, &(singleton()->a_r),
			&(singleton()->a_g), &(singleton()->a_b)) == 1)
		return (1);
	if (check_end_element(line) == 0)
		if (check_data_in_ambient() == 0)
			return (0);
	return (1);
}
