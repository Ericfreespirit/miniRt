/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comput_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:44:52 by eriling           #+#    #+#             */
/*   Updated: 2021/04/20 11:45:57 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "comput.h"
#include "miniRT.h"
#include "print_struct.h"

t_vect	get_normal_cylinder(t_data *img)
{
	t_vect	big_x;
	t_vect	big_y;
	t_vect	p;

	get_bigx_bigy(&big_x, &big_y, img->obj);
	p = vect_sum(img->origin, scale(img->dir, img->t));
	return (normalize(vect_sous(p, vect_sum(vect_obj(img->obj),
		scale(normalize(vect_orien_cylinder(img->obj)), img->zp)))));
}
