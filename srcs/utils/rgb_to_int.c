/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:05:53 by eriling           #+#    #+#             */
/*   Updated: 2021/04/07 11:35:44 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"
#include "comput.h"
#include <mlx.h>
#include <math.h>

t_vect	color_to_rgb(int color)
{
	t_vect	rgb;

	rgb.x = (color >> 16) & 0b11111111;
	rgb.y = (color >> 8) & 0b11111111;
	rgb.z = (color >> 0) & 0b11111111;
	return (rgb);
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
	else if (obj->my_type == plane)
	{
		r = obj->u.plane.r;
		g = obj->u.plane.g;
		b = obj->u.plane.b;
	}
	color = 65536 * r + 256 * g + b;
	return (color);
}

int	rgb_to_int_ambiante(void)
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
