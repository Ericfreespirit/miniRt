/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_single_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 08:45:08 by eriling           #+#    #+#             */
/*   Updated: 2021/04/03 13:56:00 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "parse.h"

int	is_single_data(char **line)
{
	if (**line == 'R')
	{
		if (parse_resolution(line) == 0)
			return (1);
		return (0);
	}
	else if (**line == 'A')
	{
		if (parse_ambient(line) == 0)
			return (1);
		return (0);
	}
	return (-1);
}
