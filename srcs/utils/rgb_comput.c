/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_comput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 08:23:36 by eriling           #+#    #+#             */
/*   Updated: 2021/04/07 08:29:36 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"
#include "comput.h"
#include <mlx.h>
#include <math.h>

int	sum_rgb(int c1, int c2)
{
	int		color;
	t_vect	v_c1;
	t_vect	v_c2;
	t_vect	res;

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
	return (color);
}

int	mult_rgb(int c_obj, int c_light)
{
	int		color;
	t_vect	v_c_obj;
	t_vect	v_c_light;
	t_vect	res;

	v_c_obj = color_to_rgb(c_obj);
	v_c_light = color_to_rgb(c_light);
	res.x = (v_c_obj.x * v_c_light.x) / 256.0;
	res.y = (v_c_obj.y * v_c_light.y) / 256.0;
	res.z = (v_c_obj.z * v_c_light.z) / 256.0;
	if (res.x > 255.0)
		res.x = 255.0;
	if (res.y > 255.0)
		res.y = 255.0;
	if (res.z > 255.0)
		res.z = 255.0;
	color = 65536 * (int)res.x + 256 * (int)res.y + (int)res.z;
	return (color);
}

int	mix_rgb(int c1, int c2, double coeff)
{
	int		color;
	t_vect	v_c1;
	t_vect	v_c2;
	t_vect	res;

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
	return (color);
}
