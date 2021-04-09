/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_orien.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:28:55 by eriling           #+#    #+#             */
/*   Updated: 2021/04/09 14:38:47 by eriling          ###   ########.fr       */
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

t_vect vect_orien_plane(t_obj *obj)
{
	t_vect res;

	res = init_vect(0, 0, 0);
	if (obj->my_type == plane)
	{
		res.x = obj->u.plane.orien_x;
		res.y = obj->u.plane.orien_y;
		res.z = obj->u.plane.orien_z;
	}
	return (res);
}
