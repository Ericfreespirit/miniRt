/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:08:28 by eriling           #+#    #+#             */
/*   Updated: 2021/03/23 18:21:58 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"
#include <mlx.h>
#include <math.h>


int intersection_sphere(t_math *math, double *t)
{
	if (math->det > 0)
	{
		math->t1 = (-math->b + sqrt(math->det)) / (2 * math->a);
		math->t2 = (-math->b - sqrt(math->det)) / (2 * math->a);
		if (math->t1 < math->t2 && math->t1 < *t)
		{
			*t = math->t1;
			return (1);
		}
		else if (math->t2 < math->t1 && math->t2 < *t)
		{
			*t = math->t2;
			return (1);
		}
	}
	else if (math->det == 0)
	{
		math->t1 = - 0.5 * math->b / math->a;
		if (math->t1 < *t)
		{
			*t = math->t1;
			return (1);
		}
	}
	return(0);
}

int	hit_sphere(t_vect dir, t_obj *cam, t_obj *sp, double *t)
{
	t_vect	v_cam;
	t_math	math;

	v_cam.x = cam->u.camera.x - sp->u.sphere.x;
	v_cam.y = cam->u.camera.y - sp->u.sphere.y;
	v_cam.z = cam->u.camera.z - sp->u.sphere.z;
	math.a = 1;
	math.b = 2.0 * dot(v_cam, dir);
	math.c = dot(v_cam, v_cam) - (sp->u.sphere.diam / 2) * (sp->u.sphere.diam / 2);
	math.det = math.b * math.b - 4 * math.a * math.c;

	if (intersection_sphere(&math, t) == 1)
		return (1);
	return (0);
}
