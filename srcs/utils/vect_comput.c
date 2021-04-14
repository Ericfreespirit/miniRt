/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_comput.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:09:13 by eriling           #+#    #+#             */
/*   Updated: 2021/04/14 13:06:54 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"
#include "comput.h"
#include <mlx.h>
#include <math.h>

t_vect	scale(t_vect v1, double t)
{
	t_vect	res;

	res.x = v1.x * t;
	res.y = v1.y * t;
	res.z = v1.z * t;
	return (res);
}

t_vect	cross_prod(t_vect v1, t_vect v2)
{
	t_vect	res;

	res.x = (v1.y * v2.z) - (v1.z * v2.y);
	res.y = (v1.z * v2.x) - (v1.x * v2.z);
	res.z = (v1.x * v2.y) - (v1.y * v2.x);
	return (res);
}

double	find_angle(t_vect v1, t_vect v2)
{
	double	numerator;
	double	denominator;
	double	res;

	numerator = dot(v1, v2);
	denominator = sqrt(dot(v1, v1) * dot(v2, v2));
	res = numerator / denominator;
	return (acos(res));
}

t_vect	normalize(t_vect v)
{
	double	norma;

	norma = sqrt(dot(v, v));
	v.x /= norma;
	v.y /= norma;
	v.z /= norma;
	return (v);
}

double	vect_length(t_vect v1, t_vect v2)
{
	double	res;

	res = 0;
	res = (v2.x - v1.x) * (v2.x - v1.x);
	res += (v2.y - v1.y) * (v2.y - v1.y);
	res += (v2.z - v1.z) * (v2.z - v1.z);
	return (sqrt(res));
}
