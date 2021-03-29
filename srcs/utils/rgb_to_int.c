/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:05:53 by eriling           #+#    #+#             */
/*   Updated: 2021/03/29 14:15:43 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"
#include <mlx.h>
#include <math.h>

int	rgb_to_int(t_obj *obj)
{
	int	r;
	int	g;
	int	b;
	int	color;

	r = 0;
	g = 0;
	b = 0;
	if (obj->my_type == sphere)
	{
		r = obj->u.sphere.r;
		g = obj->u.sphere.g;
		b = obj->u.sphere.b;
	}
	else if (obj->my_type == light)
	{
		r = obj->u.light.r;
		g = obj->u.light.g;
		b = obj->u.light.b;
	}
	color = 65536 * r + 256 * g + b;
	return (color);
}
