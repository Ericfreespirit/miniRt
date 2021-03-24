/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 10:54:46 by eriling           #+#    #+#             */
/*   Updated: 2021/03/24 09:20:01 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include "struct.h"
# define DOUBLE_MAX 1.7976931348623157e+308

void	file_rt(int fd);
size_t	ft_strlen(const char *s);
int		ft_strncmp(char *s1, char *s2, size_t n);
int		ft_strcmp(char *s1, char *s2);
int		check_file_extension(char *s1, char *s2);
int		ft_isdigit(int c);
int		get_next_line(const int fd, char **line, int buffer_size);
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
int		add_rgb(char **line, int *r, int *g, int *b);
int		add_3_float(char **line, double *x, double *y, double *z);
t_dyn	*dynarr_new(void);
int		dynarr_realloc(t_dyn *arr);
void	dynarr_cpy(t_obj **dst, t_dyn *src);
int		dynarr_push(t_dyn *arr, t_obj *obj);
void	print_camera(size_t i);
void	print_light(size_t i);
void	print_sphere(size_t i);
void	print_plane(size_t i);
void	print_square(size_t i);
void	print_cylinder(size_t i);
void	print_cylinder(size_t i);
void	print_triangle(size_t i);
void	print_struct(void);
void	print_dynarr(void);
void	dynarr_freeall(void);
t_all	*singleton(void);
t_dyn	*sg_dyn(void);
int		init_mlx_function(void);
int		red_cross(t_vars *vars);
int		switch_rt(int key, t_vars *vars);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	comput(t_data *img, t_vars *vars);
double	ft_abs(double a);
void	ray(t_data *img, double pixel_len, t_obj *cam);
double	dot(t_vect v1, t_vect v2);
int		hit_sphere(t_vect dir, t_obj *cam, t_obj *sp, double *t);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		rgb_to_int(t_obj *obj);

#endif
