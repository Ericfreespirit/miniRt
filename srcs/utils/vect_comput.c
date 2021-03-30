/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_comput.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:09:13 by eriling           #+#    #+#             */
/*   Updated: 2021/03/30 18:03:29 by eriling          ###   ########.fr       */
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

t_vect init_vect(t_vect *v)
{
	v->x = 0;
	v->y = 0;
	v->z = 0;

	return (*v);
}

void vect_obj_2(t_vect *res, t_obj *obj)
{
	if (obj->my_type == plane)
	{
		res->x = obj->u.plane.x;
		res->y = obj->u.plane.y;
		res->z = obj->u.plane.z;
	}
	else if (obj->my_type == square)
	{
		res->x = obj->u.square.x;
		res->y = obj->u.square.y;
		res->z = obj->u.square.z;
	}
	else if (obj->my_type == cylinder)
	{
		res->x = obj->u.cylinder.x;
		res->y = obj->u.cylinder.y;
		res->z = obj->u.cylinder.z;
	}
}

t_vect vect_obj(t_obj *obj)
{
	t_vect res;
	
	init_vect(&res);
	if (obj->my_type == camera)
	{
		res.x = obj->u.camera.x;
		res.y = obj->u.camera.y;
		res.z = obj->u.camera.z;
	}
	else if (obj->my_type == sphere)
	{
		res.x = obj->u.sphere.x;
		res.y = obj->u.sphere.y;
		res.z = obj->u.sphere.z;
	}
	else if (obj->my_type == light)
	{
		res.x = obj->u.light.x;
		res.y = obj->u.light.y;
		res.z = obj->u.light.z;
	}
	vect_obj_2(&res, obj);
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


t_vect vect_distance(t_vect v1, t_vect v2)
{
	t_vect res;	

	res.x = v1.x - v2.x;
	res.y = v1.y - v2.y;
	res.z = v1.z - v2.z;
	
	return (res);
}

t_vect normalize(t_vect v)
{
	double norma;

	norma = sqrt(dot(v, v));
	v.x /= norma;
	v.y /= norma;
	v.z /= norma;	
	return (v);
}