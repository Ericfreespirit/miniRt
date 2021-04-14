/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:45:20 by eriling           #+#    #+#             */
/*   Updated: 2021/04/14 13:09:22 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"
#include "libft.h"
#include "parse.h"

int	add_rgb(char **line, int *r, int *g, int *b)
{
	*r = ft_atoi_2(line);
	if (**line == ',')
		(*line)++;
	else
		return (1);
	*g = ft_atoi_2(line);
	if (**line == ',')
		(*line)++;
	else
		return (1);
	*b = ft_atoi_2(line);
	return (0);
}
