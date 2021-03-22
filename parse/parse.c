/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 08:36:31 by eriling           #+#    #+#             */
/*   Updated: 2021/03/22 09:32:07 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	parse(char *line)
{
	int	r;

	r = -1;
	if (strcmp("\0", line) == 0)
		return (0);
	r = is_single_data(&line);
	if (r == 1)
		return (0);
	else if (r == 0)
		return (1);
	r = is_mult_data(&line);
	if (r == 1)
		return (0);
	else if (r == 0)
		return (1);
	return (1);
}
