/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 09:57:13 by eriling           #+#    #+#             */
/*   Updated: 2021/04/08 20:08:17 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"
#include "parse.h"

int	parse_resolution(char **line)
{
	if (singleton()->r_x > 0 || singleton()->r_y > 0)
		return (1);
	(*line)++;
	singleton()->r_x = ft_atoi_2(line);
	singleton()->r_y = ft_atoi_2(line);
	if (check_end_element(line) == 0)
		if (singleton()->r_x >= 0 && singleton()->r_y >= 0)
			return (0);
	return (1);
}
