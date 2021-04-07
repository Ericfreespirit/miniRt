/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 09:06:48 by eriling           #+#    #+#             */
/*   Updated: 2021/04/07 11:55:31 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"
#include "comput.h"
#include "print_struct.h"
#include <mlx.h>
#include <math.h>


t_vect	vect_orien_plane(t_obj *pl)
{
	t_vect	res;

	res = init_vect(0, 0, 0);
	if (pl->my_type == plane)
	{
		res.x = pl->u.plane.orien_x;
		res.y = pl->u.plane.orien_y;
		res.z = pl->u.plane.orien_z;
	}
	return(res);
}

int hit_plane(t_vect dir, t_vect origin, t_data *img, t_obj *pl)
{
	t_math math;
	t_vect v_orien_pl;
	t_vect v_cam_to_pl;
	
	dir = normalize(dir);
	v_orien_pl = vect_orien_plane(pl);
	math.det = dot(v_orien_pl, dir);
	 if (math.det > 1e-6)
	 {
		v_cam_to_pl = vect_sous(vect_obj(pl), origin);
		math.t1 = dot(v_cam_to_pl, v_orien_pl) / math.det;
		if (math.t1 < img->t)
		{
			img->t = math.t1;
			img->obj = pl;
			img->color = rgb_to_int(pl);
			return (1);
		}
	}
	return (0);
}


// bool intersectPlane(const Vec3f &n, const Vec3f &p0, const Vec3f &l0, const Vec3f &l, float &t) 
// { 
//     // assuming vectors are all normalized
//     float denom = dotProduct(n, l); 
//     if (denom > 1e-6) { 
//         Vec3f p0l0 = p0 - l0; 
//         t = dotProduct(p0l0, n) / denom; 
//         return (t >= 0); 
//     } 
 
//     return false; 
// } 