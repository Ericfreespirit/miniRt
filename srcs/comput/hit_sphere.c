/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:08:28 by eriling           #+#    #+#             */
/*   Updated: 2021/04/05 10:06:03 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"
#include "comput.h"
#include <mlx.h>
#include <math.h>

int near_sphere(t_math *math, t_data *img)
{
	if (math->det > 0)
	{
		math->t1 = (-math->b + sqrt(math->det)) / (2 * math->a);
		math->t2 = (-math->b - sqrt(math->det)) / (2 * math->a);
		if ((math->t1 < 0 || math->t1 > img->t) &&
			(math->t2 < 0 || math->t2 > img->t))
			return (0);	
		if (math->t1 > 0 && math->t1 < img->t)
			img->t = math->t1;
		if (math->t2 > 0 && math->t2 < img->t)
			img->t = math->t2;
		return (1);
	}
	else if (math->det == 0)
	{
		math->t1 = - 0.5 * math->b / math->a;
		if (math->t1 < img->t)
		{
			img->t = math->t1;
			return (1);
		}
	}
	return(0);
}

int	hit_sphere(t_vect dir, t_vect origin, t_data *img, t_obj *sp)
{
	t_math	math;

	origin = vect_sous(origin, vect_obj(sp));
	math.a = 1;
	math.b = 2.0 * dot(origin, dir);
	math.c = dot(origin, origin) - (sp->u.sphere.diam / 2) * (sp->u.sphere.diam / 2);
	math.det = math.b * math.b - 4 * math.a * math.c;

	if (near_sphere(&math, img) == 1)
	{
		img->obj = sp;
		img->color = rgb_to_int(sp);
		return (1);
	}
	return (0);
}
