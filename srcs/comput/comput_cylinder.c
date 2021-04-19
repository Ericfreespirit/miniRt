/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comput_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:44:52 by eriling           #+#    #+#             */
/*   Updated: 2021/04/19 23:40:42 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "comput.h"

t_vect	get_normal_cylinder(t_data *img)
{
	double	xp;
	double	yp;
	t_vect	big_x;
	t_vect	big_y;
	t_vect	p;

	get_bigx_bigy(&big_x, &big_y, img->obj);
	xp = img->t * dot(img->dir, big_x)
		+ dot(vect_sous(img->origin, vect_obj(img->obj)), big_x);
	yp = img->t * dot(img->dir, big_y)
		+ dot(vect_sous(img->origin, vect_obj(img->obj)), big_y);
	p = init_vect(xp, yp, img->zp);
	return (vect_sous(p, vect_sum(vect_obj(img->obj),
		scale(vect_orien_cylinder(img->obj), img->zp))));
}