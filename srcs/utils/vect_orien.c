/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_orien.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:28:55 by eriling           #+#    #+#             */
/*   Updated: 2021/04/27 17:13:26 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "comput.h"
#include "struct.h"

t_vect	vect_orien_cam(t_obj *obj)
{
	t_vect	res;

	res = init_vect(0, 0, 0);
	if (obj->my_type == camera)
	{
		res.x = obj->u.camera.orien_x;
		res.y = obj->u.camera.orien_y;
		res.z = obj->u.camera.orien_z;
	}
	return (res);
}

t_vect	vect_orien_plane(t_obj *obj)
{
	t_vect	res;

	res = init_vect(0, 0, 0);
	if (obj->my_type == plane)
	{
		res.x = obj->u.plane.orien_x;
		res.y = obj->u.plane.orien_y;
		res.z = obj->u.plane.orien_z;
	}
	return (res);
}

t_vect	vect_orien_square(t_obj *obj)
{
	t_vect	res;

	res = init_vect(0, 0, 0);
	if (obj->my_type == square)
	{
		res.x = obj->u.square.orien_x;
		res.y = obj->u.square.orien_y;
		res.z = obj->u.square.orien_z;
	}
	return (res);
}

t_vect	vect_orien_cylinder(t_obj *obj)
{
	t_vect	res;

	res = init_vect(0, 0, 0);
	if (obj->my_type == cylinder)
	{
		res.x = obj->u.cylinder.orien_x;
		res.y = obj->u.cylinder.orien_y;
		res.z = obj->u.cylinder.orien_z;
	}
	return (res);
}
