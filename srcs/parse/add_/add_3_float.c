/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_3_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 13:16:52 by eriling           #+#    #+#             */
/*   Updated: 2021/04/03 13:54:20 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"
#include "libft.h"
#include "parse.h"

int	add_3_float(char **line, double *x, double *y, double *z)
{
	*x = ft_atof_2(line);
	if (**line == ',')
		(*line)++;
	else
		return (1);
	*y = ft_atof_2(line);
	if (**line == ',')
		(*line)++;
	else
		return (1);
	*z = ft_atof_2(line);
	return (0);
}
