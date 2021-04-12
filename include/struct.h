/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 10:55:05 by eriling           #+#    #+#             */
/*   Updated: 2021/04/11 18:20:03 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include <stddef.h>

typedef struct s_all
{
	// Resolution
	int		r_x;
	int		r_y;
	// Ambiante
	int		a;
	double	a_ran_light;
	int		a_r;
	int		a_g;
	int		a_b;
}							t_all;

typedef struct s_dyn
{
	struct s_obj	**obj;
	size_t			size;
	size_t			capacity;
}				t_dyn;

enum e_type_obj
{
	camera,
	light,
	sphere,
	plane,
	square,
	cylinder,
	triangle
};
typedef struct s_c
{
	double	x;
	double	y;
	double	z;
	double	orien_x;
	double	orien_y;
	double	orien_z;
	int		fov;
}							t_c;

typedef struct s_l
{
	double	x;
	double	y;
	double	z;
	double	rat_l;
	int		r;
	int		g;
	int		b;
}								t_l;

typedef struct s_sp
{
	double	x;
	double	y;
	double	z;
	double	diam;
	int		r;
	int		g;
	int		b;
}							t_sp;

typedef struct s_pl
{
	double	x;
	double	y;
	double	z;
	double	orien_x;
	double	orien_y;
	double	orien_z;
	int		r;
	int		g;
	int		b;
}							t_pl;

typedef struct s_sq
{
	double	x;
	double	y;
	double	z;
	double	orien_x;
	double	orien_y;
	double	orien_z;
	double	high;
	int		r;
	int		g;
	int		b;
}								t_sq;

typedef struct s_cy
{
	double	x;
	double	y;
	double	z;
	double	orien_x;
	double	orien_y;
	double	orien_z;
	double	diam;
	double	high;
	int		r;
	int		g;
	int		b;
}								t_cy;

typedef struct s_tr
{
	double	x_1;
	double	y_1;
	double	z_1;
	double	x_2;
	double	y_2;
	double	z_2;
	double	x_3;
	double	y_3;
	double	z_3;
	int		r;
	int		g;
	int		b;
}								t_tr;

union u_obj
{
	struct s_c	 camera;
	struct s_l	 light;
	struct s_sp	 sphere;
	struct s_pl	 plane;
	struct s_sq	 square;
	struct s_cy	 cylinder;
	struct s_tr	 triangle;
}	;

typedef struct s_obj
{
	enum e_type_obj	my_type;
	union u_obj		u;
}								t_obj;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			x;
	int			y;
	double		t;
	t_obj		*obj;
	t_obj		*cam;
	int			id_obj;
	int			color;
	double		pixel_len;
	double		total_light_coeff;
	int			total_light_color;
}				t_data;

typedef struct s_vars
{
	void		*mlx;
	void		*mlx_win;
	t_data		img;
}				t_vars;

typedef struct s_vect
{
	double	x;
	double	y;
	double	z;
}				t_vect;

typedef struct s_math
{
	double	a;
	double	b;
	double	c;
	double	det;
	double	t1;
	double	t2;
}				t_math;

typedef struct s_last_hit
{
	double	t;
	t_obj	obj;
}				t_last_hit;	
#endif
