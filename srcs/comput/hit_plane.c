/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 09:06:48 by eriling           #+#    #+#             */
/*   Updated: 2021/04/09 19:03:45 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"
#include "comput.h"
#include "print_struct.h"
#include <mlx.h>
#include <math.h>

int hit_plane(t_vect dir, t_vect origin, t_data *img, t_obj *pl)
{
	t_math math;
	t_vect v_orien_pl;
	t_vect v_cam_to_pl;
	
	v_orien_pl = vect_orien_plane(pl);
	v_orien_pl = normalize(v_orien_pl);
	math.det = dot(v_orien_pl, dir);
	if (math.det > 1e-6 || math.det < 1e-6)
	{
		v_cam_to_pl = vect_sous(vect_obj(pl), origin);
		math.t1 = dot(v_cam_to_pl, v_orien_pl) / math.det;
		if (math.t1 > 0 && math.t1 < img->t)
		{
			img->t = math.t1;
			img->obj = pl;
			img->color = rgb_to_int(pl);
			return (1);
		}
	}
	return (0);
}