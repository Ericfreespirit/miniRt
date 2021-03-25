/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_comput.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:09:13 by eriling           #+#    #+#             */
/*   Updated: 2021/03/25 17:10:50 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"
#include <mlx.h>
#include <math.h>

double	dot(t_vect v1, t_vect v2)
{
	double	res;

	res = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (res);
}

t_vect vect_sum(t_vect v1, t_vect v2)
{
	t_vect res;

	res.x = v1.x + v2.x;
	res.y = v1.y + v2.y;
	res.z = v1.z + v2.z;

	return (res);
}

t_vect vect_origin(t_obj *cam)
{
	t_vect res;
	
	res.x = cam->u.camera.x;
	res.y = cam->u.camera.y;
	res.z = cam->u.camera.z;

	return (res);
}

t_vect scale(t_vect v1, double t)
{
	t_vect res;
	
	res.x = v1.x *= t;
	res.y = v1.y *= t;
	res.z = v1.z *= t;

	return (res);
}

t_vect vect_light(t_l l)
{
	t_vect res;
	
	res.x =  l.x;
	res.y =  l.y;
	res.z =  l.z;

	return (res);
	
}