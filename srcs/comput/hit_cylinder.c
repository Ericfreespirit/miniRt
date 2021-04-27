/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 12:48:03 by eriling           #+#    #+#             */
/*   Updated: 2021/04/27 17:00:22 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "comput.h"
#include "print_struct.h"
#include "miniRT.h"

void	get_bigx_bigy(t_vect *big_x, t_vect *big_y, t_obj *cy)
{
	t_vect	vect_orien_cy;

	vect_orien_cy = normalize(vect_orien_cylinder(cy));
	*big_x = init_vect(0, 1, 0);
	*big_y = init_vect(0, 0, 1);
	if (vect_orien_cy.x == 0 && (vect_orien_cy.y == 1 || vect_orien_cy.y == -1)
		&& vect_orien_cy.z == 0)
		*big_x = init_vect(1, 0, 0);
	*big_x = normalize(cross_prod(*big_x, vect_orien_cy));
	*big_y = normalize(cross_prod(vect_orien_cy, *big_x));
}

double	get_zp(double t, t_data *img, t_obj *cy)
{
	double	zp;
	t_vect	big_z;

	big_z = normalize(vect_orien_cylinder(cy));
	zp = t * dot(img->dir, big_z)
		+ dot(vect_sous(img->origin, vect_obj(cy)), big_z);
	if (fabs(zp) <= cy->u.cylinder.high / 2.0)
		return (zp);
	return (cy->u.cylinder.high + 1.0);
}

int	is_det_zero_inter_near(t_math *math, t_data *img, t_obj *cy)
{
	math->t1 = -0.5 * math->b / math->a;
	if (math->t1 > 0 && math->t1 < img->t
		&& get_zp(math->t1, img, cy) <= cy->u.cylinder.high / 2.0)
	{
		img->t = math->t1;
		return (1);
	}
	return (0);
}

int	is_inter_in_xp_yp_zp(t_math *math, t_data *img, t_obj *cy)
{
	if (math->det > 0)
	{
		math->t1 = (-math->b + sqrt(math->det)) / (2.0 * math->a);
		math->t2 = (-math->b - sqrt(math->det)) / (2.0 * math->a);
		if ((math->t1 < 0 || math->t1 > img->t)
			&& (math->t2 < 0 || math->t2 > img->t))
			return (0);
		if (math->t1 > 0 && math->t1 < img->t
			&& get_zp(math->t1, img, cy) <= cy->u.cylinder.high / 2.0)
			img->t = math->t1;
		if (math->t2 > 0 && math->t2 < img->t
			&& get_zp(math->t2, img, cy) <= cy->u.cylinder.high / 2.0)
			img->t = math->t2;
		return (1);
	}
	else if (math->det == 0)
		if (is_det_zero_inter_near(math, img, cy) == 1)
			return (1);
	return (0);
}

int	hit_cylinder(t_vect dir, t_vect origin, t_data *img, t_obj *cy)
{
	t_math	math;
	t_vect	big_x;
	t_vect	big_y;

	get_bigx_bigy(&big_x, &big_y, cy);
	img->origin = origin;
	img->dir = dir;
	math.a = pow(dot(dir, big_x), 2) + pow(dot(dir, big_y), 2);
	math.b = 2.0 * (dot(dir, big_x)
			* dot(vect_sous(origin, vect_obj(cy)), big_x)
			+ dot(dir, big_y) * dot(vect_sous(origin, vect_obj(cy)), big_y));
	math.c = pow(dot(vect_sous(origin, vect_obj(cy)), big_x), 2)
		+ pow(dot(vect_sous(origin, vect_obj(cy)), big_y), 2)
		- cy->u.cylinder.diam;
	math.det = math.b * math.b - 4.0 * math.a * math.c;
	if (is_inter_in_xp_yp_zp(&math, img, cy) == 1)
	{
		img->zp = get_zp(img->t, img, cy);
		img->obj = cy;
		img->color = rgb_to_int(cy);
		return (1);
	}
	return (0);
}
