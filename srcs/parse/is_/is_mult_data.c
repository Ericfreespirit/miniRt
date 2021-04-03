/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_mult_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 09:16:34 by eriling           #+#    #+#             */
/*   Updated: 2021/04/03 13:55:56 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "parse.h"

int	is_single_letter(char **line)
{
	if (ft_strncmp("c ", *line, 2) == 0)
	{
		if (parse_camera(line) == 0)
			return (1);
		return (0);
	}
	else if (**line == 'l')
	{
		if (parse_light(line) == 0)
			return (1);
		return (0);
	}
	return (-1);
}

int	is_double_letter_part1(char **line)
{
	if (ft_strncmp("sp", *line, 2) == 0)
	{
		if (parse_sphere(line) == 0)
			return (1);
		return (0);
	}
	else if (ft_strncmp("pl", *line, 2) == 0)
	{
		if (parse_plane(line) == 0)
			return (1);
		return (0);
	}
	else if (ft_strncmp("sq", *line, 2) == 0)
	{
		if (parse_square(line) == 0)
			return (1);
		return (0);
	}
	return (-1);
}

int	is_double_letter_part2(char **line)
{
	if (ft_strncmp("cy", *line, 2) == 0)
	{
		 if (parse_cylinder(line) == 0)
			return (1);
		return (0);
	}
	else if (ft_strncmp("tr", *line, 2) == 0)
	{
		if (parse_triangle(line) == 0)
			return (1);
		return (0);
	}
	return (-1);
}

int	is_mult_data(char **line)
{
	if (is_double_letter_part1(line) == 1 || is_double_letter_part2(line) == 1
		|| is_single_letter(line) == 1)
		return (1);
	else if (is_double_letter_part1(line) == 0
		|| is_double_letter_part2(line) == 0 || is_single_letter(line) == 0)
		return (0);
	return (-1);
}
