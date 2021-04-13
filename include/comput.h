/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comput.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:06:41 by eriling           #+#    #+#             */
/*   Updated: 2021/04/13 14:13:18 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUT_H
# define COMPUT_H

# include "struct.h"
# include "orientation_matrix.h"
# define DOUBLE_MAX 1.7976931348623157e+308

int		mlx_function(void);
int		red_cross(t_vars *vars);
int		switch_rt(int key, t_vars *vars);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	comput_all_cam_view(t_data *img, t_vars *vars);
double	ft_abs(double a);
void	ray(t_data *img, t_obj *cam);
double	dot(t_vect v1, t_vect v2);
int		hit_sphere(t_vect dir, t_vect origin, t_data *img, t_obj *sp);
void	hit_light(t_vect dir, t_vect origin, t_obj *light, t_data *img);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		rgb_to_int(t_obj *obj);
t_vect	vect_sum(t_vect v1, t_vect v2);
t_vect	vect_cam(t_obj *cam);
t_vect	scale(t_vect v1, double t);
t_vect	vect_light(t_l l);
t_vect	vect_obj(t_obj *obj);
t_vect	ray_dir_cam(t_data img);
t_vect	ray_dir_obj(t_vect v1, t_vect v2);
t_vect	vect_sous(t_vect v1, t_vect v2);
t_vect	normalize(t_vect v);
int		color_coeff(int color, double coeff);
void	add_ambiante(t_data *img);
int		mix_rgb(int c1, int c2, double coeff);
int		sum_rgb(int c1, int c2);
int		rgb_to_int_ambiante(void);
int		mult_rgb(int c_obj, int c_light);
void	enlight_figure(t_vect origin, t_data *img, t_obj *light, t_vect dir);
void	comput_all_light(t_data *img, t_vect origin);
t_vect	cross_prod(t_vect v1, t_vect v2);
t_vect	vect_orien_cam(t_obj *obj);
double	find_angle(t_vect v1, t_vect v2);
t_vect	comput_orien_matrix(t_matr matrix, t_vect v);
t_vect	init_vect(double x, double y, double z);
t_matr	orien_matrix(t_vect v, double angle);
t_vect	color_to_rgb(int color);
int			hit_plane(t_vect dir, t_vect origin, t_data *img, t_obj *pl);
t_vect	vect_orien_plane(t_obj *obj);
double	vect_length(t_vect v1, t_vect v2);
t_vect get_vect_triangle(int num, t_obj *triangle);
t_vect get_normal_triangle(t_obj *triangle);
int hit_triangle(t_vect dir, t_vect origin,t_data *img, t_obj *tr);
t_vect comput_rot_axis(t_obj *cam);

#endif
