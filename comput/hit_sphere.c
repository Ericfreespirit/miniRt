/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:08:28 by eriling           #+#    #+#             */
/*   Updated: 2021/03/23 17:59:23 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"
#include <mlx.h>
#include <math.h>


int	hit_sphere(t_vect dir, t_obj *cam, t_obj *sp, double *t)
{
	t_vect	v_cam;
	
	double	a;
	double	b;
	double	c;
	double	det;
	double t1;
	double t2;

	v_cam.x = cam->u.camera.x - sp->u.sphere.x;
	v_cam.y = cam->u.camera.y - sp->u.sphere.y;
	v_cam.z = cam->u.camera.z - sp->u.sphere.z;
	a = 1;
	b = 2.0 * dot(v_cam, dir);
	c = dot(v_cam, v_cam) - (sp->u.sphere.diam / 2) * (sp->u.sphere.diam / 2);
	det = b * b - 4 * a * c;
	if (det > 0)
	{
		t1 = (-b + sqrt(det)) / (2 * a);
		t2 = (-b - sqrt(det)) / (2 * a);
		if (t1 < t2 && t1 < *t)
		{
			*t = t1;
			return (1);
		}
		else if (t2 < t1 && t2 < *t)
		{
			*t = t2;
			return (1);
		}
	}
	else if (det == 0)
	{
		t1 = - 0.5 * b / a;
		if (t1 < *t)
		{
			*t = t1;
			return (1);
		}
	}
	return (0);
}
