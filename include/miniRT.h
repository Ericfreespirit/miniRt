/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 10:54:46 by eriling           #+#    #+#             */
/*   Updated: 2021/04/22 13:45:00 by eriling          ###   ########.fr       */
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
# include "math.h"
# define	WINDOW 0
# define	SAVE 1

void	file_rt(int fd, int win_or_save);
size_t	ft_strlen(const char *s);
int		ft_strncmp(char *s1, char *s2, size_t n);
int		ft_strcmp(char *s1, char *s2);
int		ft_isdigit(int c);
int		get_next_line(const int fd, char **line, int buffer_size);
int		add_rgb(char **line, int *r, int *g, int *b);
int		add_3_float(char **line, double *x, double *y, double *z);
int		dynarr_realloc(t_dyn *arr);
void	dynarr_cpy(t_obj **dst, t_dyn *src);
int		dynarr_push(t_dyn *arr, t_obj *obj);
void	dynarr_freeall(void);
t_dyn	*dynarr_new(void);
t_all	*singleton(void);
t_dyn	*sg_dyn(void);
int		ft_image(t_vars *vars);
int		ft_isspace(int c);
int		check_end_element(char **line);

#endif
