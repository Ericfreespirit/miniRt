/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 12:48:03 by eriling           #+#    #+#             */
/*   Updated: 2021/04/15 15:27:28 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "comput.h"
#include "print_struct.h"
#include "miniRT.h"

void get_bigx_bigy(t_vect *big_x, t_vect *big_y)
{
	t_vect v_orien_cy;

	v_orien_cy = normalize(vect_orien_cylinder(cy));
	*big_x = init_vect(0, 1, 0);
	*big_y = init_vect(1, 0, 0);
	if (vect_orien_cy.x == 0 && (vect_orien_cy.y == 1 || vect_orien_cy.y == -1)
		&& vect_orien_cy.z == 0)
		*big_x = init_vect(1, 0, 0);
	*big_x = cross_prod(big_x, vect_orien_cy);
	*big_y = cross_prod(vect_orien_sq, big_x);
}

int is_inter_in_cy(t_math *math, t_data *img)
{
	if (math->det > 0)
	{
		math->t1 = (-math->b + sqrt(math->det)) / (2 * math->a);
		math->t2 = (-math->b - sqrt(math->det)) / (2 * math->a);
		// CHECK FOR Zp
		if ((math->t1 < 0 || math->t1 > img->t)
			&& (math->t2 < 0 || math->t2 > img->t))
			return (0);
		if (math->t1 > 0 && math->t1 < img->t)
			img->t = math->t1;
		if (math->t2 > 0 && math->t2 < img->t)
			img->t = math->t2;
		return (1);
	}
	else if (math->det == 0)
	{
		math->t1 = -0.5 * math->b / math->a;
		// CHECK FOR Zp
		if (math->t1 < img->t)
		{
			img->t = math->t1;
			return (1);
		}
	}
	return (0);
}

int	hit_cylinder(t_vect dir, t_vect origin, t_data *img, t_obj *cy)
{
	t_math;
	t_vect big_x;
	t_vect big_y;

	get_bigx_bigy(&big_x, &big_y);
	math.a = pow(dot(dir, big_x), 2) + pow(dot(dir, big_y), 2);
	math.b = 2 * (dot(dir, big_x) * dot(vect_sous(origin, vect_obj(cy), big_x))
		+ dot(dir, big_y) * dot(vect_sous(origin, vect_obj(cy), big_y)));
	math.c = pow(dot(vect_sous(origin, vect_obj(cy)), big_x), 2)
		+ pow(dot(vect_sous(origin, vect_obj(cy)), big_y), 2)
		- cy->u.cylinder.diam;
	math.det = math.b * math.b - 4 * math.a * math.c;
	if (is_inter_in_cy(&math, img) == 1)
	{
		img->obj = cy;
		img->color = rgb_to_int(cy);
		return (1);
	}
	return (0);
}