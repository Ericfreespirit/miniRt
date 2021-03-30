/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:05:53 by eriling           #+#    #+#             */
/*   Updated: 2021/03/30 17:10:16 by eriling          ###   ########.fr       */
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


int mix_rgb(int c1, int c2)
{
	int color;
	t_vect v_c1;
	t_vect v_c2;
	t_vect res;

	v_c1 = color_to_rgb(c1);
	v_c2 = color_to_rgb(c2);
	res.x = 0.5 * v_c1.x + 0,5 * v_c2.x;
	res.y = 0.5 * v_c1.y + 0,5 * v_c2.y;
	res.z = 0.5 * v_c1.z + 0,5 * v_c2.z;
	color = 65536 * res.x + 256 * res.y + res.z;
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
