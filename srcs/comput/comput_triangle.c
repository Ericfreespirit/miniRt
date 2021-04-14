/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comput_triangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:16:13 by eriling           #+#    #+#             */
/*   Updated: 2021/04/14 13:05:09 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "comput.h"

t_vect	get_vect_triangle(int num, t_obj *triangle)
{
	t_vect	res;

	res = init_vect(0, 0, 0);
	if (num == 1)
	{
		res.x = triangle->u.triangle.x_1;
		res.y = triangle->u.triangle.y_1;
		res.z = triangle->u.triangle.z_1;
	}
	else if (num == 2)
	{
		res.x = triangle->u.triangle.x_2;
		res.y = triangle->u.triangle.y_2;
		res.z = triangle->u.triangle.z_2;
	}
	else if (num == 3)
	{
		res.x = triangle->u.triangle.x_3;
		res.y = triangle->u.triangle.y_3;
		res.z = triangle->u.triangle.z_3;
	}
	return (res);
}

t_vect	get_normal_triangle(t_obj *triangle)
{
	t_vect	a;
	t_vect	b;
	t_vect	c;
	t_vect	res;

	res = init_vect(0, 0, 0);
	a = get_vect_triangle(1, triangle);
	b = get_vect_triangle(2, triangle);
	c = get_vect_triangle(3, triangle);
	res = cross_prod(vect_sous(b, a), vect_sous(c, a));
	return (res);
}
