/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comput.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:06:41 by eriling           #+#    #+#             */
/*   Updated: 2021/04/29 14:37:32 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUT_H
# define COMPUT_H

# include "struct.h"
# include "orientation_matrix.h"
# define DOUBLE_MAX 1.7976931348623157e+308

int		mlx_function(int win_or_save);
int		red_cross(t_vars *vars);
int		key_press(int key, t_vars *vars);
int		ft_image(t_vars *vars);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_scene	*comput_all_cam_view(t_vars	*vars);
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
int		hit_plane(t_vect dir, t_vect origin, t_data *img, t_obj *pl);
t_vect	vect_orien_plane(t_obj *obj);
double	vect_length(t_vect v1, t_vect v2);
t_vect	get_vect_triangle(int num, t_obj *triangle);
t_vect	get_normal_triangle(t_obj *triangle);
int		hit_triangle(t_vect dir, t_vect origin, t_data *img, t_obj *tr);
t_vect	comput_rot_axis(t_obj *cam);
int		hit_square (t_vect dir, t_vect origin, t_data *img, t_obj *sq);
t_vect	vect_orien_square(t_obj *obj);
int		hit_cylinder(t_vect dir, t_vect origin, t_data *img, t_obj *cy);
t_vect	vect_orien_cylinder(t_obj *obj);
t_vect	get_normal_cylinder(t_data *img);
void	get_bigx_bigy(t_vect *big_x, t_vect *big_y, t_obj *cy);
void	output(t_scene *array, int win_or_save, t_vars *vars);
void	free_program(t_vars *vars);
size_t	count_cam(void);
void	create_bmp(t_vars *vars);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif
