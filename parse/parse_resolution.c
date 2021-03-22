/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 09:57:13 by eriling           #+#    #+#             */
/*   Updated: 2021/02/18 16:39:21 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"

int	parse_resolution(char **line)
{
	if (singleton()->r_x > 0 || singleton()->r_y > 0)
		return (1);
	(*line)++;
	singleton()->r_x = ft_atoi_2(line);
	singleton()->r_y = ft_atoi_2(line);
	if (**line == 0)
		if (singleton()->r_x >= 0 && singleton()->r_y >= 0)
			return (0);
	return (1);
}
