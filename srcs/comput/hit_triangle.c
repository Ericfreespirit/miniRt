/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_triangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:37:49 by eriling           #+#    #+#             */
/*   Updated: 2021/04/13 13:02:27 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "comput.h"
#include "print_struct.h"
#include "miniRT.h"

int	is_inter_in_triangle(t_vect intersection, t_obj *tr)
{
	t_math math;

	math.v1 = vect_sous(get_vect_triangle(2, tr), get_vect_triangle(1, tr));
	math.v2 = vect_sous(intersection, get_vect_triangle(1, tr));
	math.v3 = cross_prod(math.v1, math.v2);
	math.v4 = vect_sous(get_vect_triangle(3, tr), get_vect_triangle(1, tr));
	math.v5 = cross_prod(math.v1, math.v4);
	math.a = dot(math.v3, math.v5);

	math.v1 = vect_sous(get_vect_triangle(3, tr), get_vect_triangle(2, tr));
	math.v2 = vect_sous(intersection, get_vect_triangle(2, tr));
	math.v3 = cross_prod(math.v1, math.v2);
	math.v4 = vect_sous(get_vect_triangle(1, tr), get_vect_triangle(2, tr));
	math.v5 = cross_prod(math.v1, math.v4);
	math.b = dot(math.v3, math.v5);

	math.v1 = vect_sous(get_vect_triangle(1, tr), get_vect_triangle(3, tr));
	math.v2 = vect_sous(intersection, get_vect_triangle(3, tr));
	math.v3 = cross_prod(math.v1, math.v2);
	math.v4 = vect_sous(get_vect_triangle(2, tr), get_vect_triangle(3, tr));
	math.v5 = cross_prod(math.v1, math.v4);
	math.c = dot(math.v3, math.v5);

	if (math.a > 0 && math.b > 0 && math.c > 0)
		return (1);
	return (0);
}

int hit_triangle(t_vect dir, t_vect origin,t_data *img, t_obj *tr)
{
	t_math math;
	t_vect normal_tr;
	t_vect cam_to_tr;
	t_vect intersection;
	
	normal_tr = get_normal_triangle(tr);
	normal_tr = normalize(normal_tr);
	math.det = dot(normal_tr, dir);
	if (math.det > 1e-6 || math.det < 1e-6)
	{
		cam_to_tr = vect_sous(get_vect_triangle(1, tr), origin);
		math.t1 = dot(cam_to_tr, normal_tr) / math.det;
		if (math.t1 > 0)
		{
			intersection = vect_sum(origin, scale(dir, math.t1));
			if (is_inter_in_triangle(intersection, tr) == 1)
			{
				img->t = math.t1;
				img->obj = tr;
				img->color = rgb_to_int(tr);
				return (1);
			}
		}
	}
	return (0);
}
