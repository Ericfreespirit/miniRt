/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comput_rot_axis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 14:04:07 by eriling           #+#    #+#             */
/*   Updated: 2021/04/14 13:05:36 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "comput.h"
#include "struct.h"

t_vect	comput_rot_axis(t_obj *cam)
{
	t_vect	orien_cam;
	t_vect	res;

	orien_cam = normalize(vect_orien_cam(cam));
	if (orien_cam.x == 0 && orien_cam.y == 0
		&& (orien_cam.z == 1 || orien_cam.z == -1))
		orien_cam = init_vect(1, 0, 0);
	res = cross_prod(init_vect(0, 0, 1), orien_cam);
	return (res);
}
