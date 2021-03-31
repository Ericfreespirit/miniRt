/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:05:53 by eriling           #+#    #+#             */
/*   Updated: 2021/03/31 13:50:55 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"
#include <mlx.h>
#include <math.h>


t_vect color_to_rgb(int color)
{
	t_vect rgb;
	rgb.x = (color >> 16) & 0b11111111;
	rgb.y = (color >> 8) & 0b11111111;
	rgb.z = (color >> 0) & 0b11111111;
	return (rgb);
}


int mix_rgb(int c1, int c2, double coeff)
{
	int color;
	t_vect v_c1;
	t_vect v_c2;
	t_vect res;

	if (coeff > 1)
		coeff = 1;
	v_c1 = color_to_rgb(c1);
	v_c2 = color_to_rgb(c2);
	res.x = coeff * v_c1.x + (1.0 - coeff) * v_c2.x;
	res.y = coeff * v_c1.y + (1.0 - coeff) * v_c2.y;
	res.z = coeff * v_c1.z + (1.0 - coeff) * v_c2.z;
	if (res.x > 255.0)
		res.x = 255.0;
	if (res.y > 255.0)
		res.y = 255.0;
	if (res.z > 255.0)
		res.z = 255.0;
	color = 65536 * (int)res.x + 256 * (int)res.y + (int)res.z;
	return(color);
}

int sum_rgb(int c1, int c2)
{
	int color;
	t_vect v_c1;
	t_vect v_c2;
	t_vect res;

	v_c1 = color_to_rgb(c1);
	v_c2 = color_to_rgb(c2);
	res.x = v_c1.x + v_c2.x;
	res.y = v_c1.y + v_c2.y;
	res.z = v_c1.z + v_c2.z;
	if (res.x > 255.0)
		res.x = 255.0;
	if (res.y > 255.0)
		res.y = 255.0;
	if (res.z > 255.0)
		res.z = 255.0;
	color = 65536 * (int)res.x + 256 * (int)res.y + (int)res.z;
	return(color);
}

int	rgb_to_int(t_obj *obj)
{
	int	r;
	int	g;
	int	b;
	int	color;

	r = 0;
	g = 0;
	b = 0;
	if (obj->my_type == sphere)
	{
		r = obj->u.sphere.r;
		g = obj->u.sphere.g;
		b = obj->u.sphere.b;
	}
	else if (obj->my_type == light)
	{
		r = obj->u.light.r;
		g = obj->u.light.g;
		b = obj->u.light.b;
	}
	color = 65536 * r + 256 * g + b;
	return (color);
}

int rgb_to_int_ambiante()
{
	int	r;
	int	g;
	int	b;
	int	color;

	r = 0;
	g = 0;
	b = 0;

	r = singleton()->a_r;
	g = singleton()->a_g;
	b = singleton()->a_b;
	color = 65536 * r + 256 * g + b;
	return (color);
}
