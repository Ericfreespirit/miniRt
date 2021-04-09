/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end_element.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 19:55:34 by eriling           #+#    #+#             */
/*   Updated: 2021/04/08 20:08:30 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int check_end_element(char **line)
{
	while (**line && ft_isspace(**line))
		(*line)++;	
	if (**line == 0)
		return (0);
	else
		return (1);	
}