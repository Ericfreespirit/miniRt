/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 13:47:22 by eriling           #+#    #+#             */
/*   Updated: 2021/04/03 14:11:51 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

int		parse(char *line);
int		is_single_data(char **line);
int		parse_resolution(char **line);
int		parse_ambient(char **line);
int		parse_camera(char **line);
int		parse_light(char **line);
int		is_mult_data(char **line);
int		parse_sphere(char **line);
int		parse_plane(char **line);
int		parse_square(char **line);
int		parse_cylinder(char **line);
int		parse_triangle(char **line);
int		ft_atoi_2(char **str);

#endif