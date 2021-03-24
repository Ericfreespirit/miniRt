/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:08:28 by eriling           #+#    #+#             */
/*   Updated: 2021/03/24 11:44:34 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"
#include <mlx.h>
#include <math.h>

int near_sphere(t_math *math, double *t)
{
	if (math->det > 0)
	{
		math->t1 = (-math->b + sqrt(math->det)) / (2 * math->a);
		math->t2 = (-math->b - sqrt(math->det)) / (2 * math->a);
		if ((math->t1 < 0 || math->t1 > *t) &&
			(math->t2 < 0 || math->t2 > *t))
			return (1);	
		if (math->t1 > 0 && math->t1 < *t)
			*t = math->t1;
		if (math->t2 > 0 && math->t2 < *t)
			*t = math->t2;
		return (0);
	}
	else if (math->det == 0)
	{
		math->t1 = - 0.5 * math->b / math->a;
		if (math->t1 < *t)
		{
			*t = math->t1;
			return (0);
		}
	}
	return(1);
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

	if (near_sphere(&math, t) == 0)
		return (0);
	return (1);
}
