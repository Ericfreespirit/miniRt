/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 09:33:08 by eriling           #+#    #+#             */
/*   Updated: 2021/04/14 11:26:59 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "comput.h"
#include "print_struct.h"
#include "miniRT.h"

int	is_inter_in_square(t_vect intersection, t_obj *sq, t_vect vect_orien_sq)
{
	double	x;
	double	y;
	t_vect	inter_to_sq;
	t_vect	big_x;

	big_x = init_vect(0, 1, 0);
	inter_to_sq = vect_sous(intersection, vect_obj(sq));
	if (vect_orien_sq.x == 0 && (vect_orien_sq.y == 1 || vect_orien_sq.y == -1) && vect_orien_sq.z == 0 )
		big_x = init_vect(1, 0, 0);
	big_x = cross_prod(big_x, vect_orien_sq);
	x = fabs(dot(inter_to_sq, big_x));
	y = fabs(dot(inter_to_sq, cross_prod(vect_orien_sq, big_x)));
	if (x < sq->u.square.high / 2.0 && y < sq->u.square.high / 2.0)
		return (1);
	return (0);
}

int hit_square (t_vect dir, t_vect origin, t_data *img, t_obj *sq)
{
	t_math	math;
	t_vect	v_orien_sq;
	t_vect	v_cam_to_sq;
	t_vect	intersection;

	v_orien_sq = normalize(vect_orien_square(sq));
	math.det = dot(v_orien_sq, dir);
	if (math.det > 1e-6 || math.det < 1e-6)
	{
		v_cam_to_sq = vect_sous(vect_obj(sq), origin);
		math.t1 = dot(v_cam_to_sq, v_orien_sq) / math.det;
		if (math.t1 > 0 && math.t1 < img->t)
		{
			intersection = vect_sum(origin, scale(dir, math.t1));
			if (is_inter_in_square(intersection, sq, v_orien_sq) == 1)
			{
				img->t = math.t1;
				img->obj = sq;
				img->color = rgb_to_int(sq);
				return (1);
			}
		}
	}
	return (0);
}