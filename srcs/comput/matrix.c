/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 10:22:32 by eriling           #+#    #+#             */
/*   Updated: 2021/04/07 07:58:53 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "orientation_matrix.h"
#include "comput.h"
#include "orientation_matrix.h"
#include "struct.h"

t_matr	orien_matrix(t_vect v, double angle)
{
	t_matr matrix;

	matrix.a1 = (v.x * v.x) * (1 - cos(angle)) + cos(angle);
	matrix.a2 = (v.x * v.y) * (1 - cos(angle)) + v.z * sin(angle);
	matrix.a3 = (v.x * v.z) * (1 - cos(angle)) - v.y * sin(angle);
	
	matrix.b1 = (v.x * v.y) * (1 - cos(angle)) - v.z * sin(angle);
	matrix.b2 = (v.y * v.y) * (1 - cos(angle)) + cos(angle);
	matrix.b3 = (v.y * v.z) * (1 - cos(angle)) + v.x * sin(angle);
	
	matrix.c1 = (v.x * v.z) * (1 - cos(angle)) + v.y * sin(angle);
	matrix.c2 = (v.y * v.z) * (1 - cos(angle)) - v.x * sin(angle);
	matrix.c3 = (v.z * v.z) * (1 - cos(angle)) + cos(angle);

	return(matrix);
}

t_vect comput_orien_matrix(t_matr matrix, t_vect v)
{
	t_vect u;

	u.x = (v.x * matrix.a1) + (v.y * matrix.b1) + (v.z * matrix.c1);
	u.y = (v.x * matrix.a2) + (v.y * matrix.b2) + (v.z * matrix.c2);
	u.z = (v.x * matrix.a3) + (v.y * matrix.b3) + (v.z * matrix.c3);

	return (u);
}
