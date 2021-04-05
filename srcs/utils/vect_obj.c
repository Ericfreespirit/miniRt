/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 10:01:11 by eriling           #+#    #+#             */
/*   Updated: 2021/04/05 17:30:10 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"
#include <mlx.h>

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

t_vect vect_orien_cam(t_obj *obj)
{
	t_vect res;

	init_vect(&res);
	if (obj->my_type == camera)
	{
		res.x = obj->u.camera.orien_x;
		res.y = obj->u.camera.orien_y;
		res.z = obj->u.camera.orien_z;
	}
	return(res);
}