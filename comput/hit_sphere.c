/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:08:28 by eriling           #+#    #+#             */
/*   Updated: 2021/03/22 14:08:50 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"
#include <mlx.h>
#include <math.h>

int	hit_sphere(t_vect dir, t_obj *cam, t_obj *sp)
{
	t_vect	v_cam;
	double	a;
	double	b;
	double	c;
	double	discriminant;

	v_cam.x = cam->u.camera.x - sp->u.sphere.x;
	v_cam.y = cam->u.camera.y - sp->u.sphere.y;
	v_cam.z = cam->u.camera.z - sp->u.sphere.z;
	a = 1;
	b = 2.0 * dot(v_cam, dir);
	c = dot(v_cam, v_cam) - (sp->u.sphere.diam / 2) * (sp->u.sphere.diam / 2);
	discriminant = b * b - 4 * a * c;
	if (discriminant > 0)
		return (1);
	return (0);
}
