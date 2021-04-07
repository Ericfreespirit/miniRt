/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation_matrix.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 09:52:01 by eriling           #+#    #+#             */
/*   Updated: 2021/04/07 08:02:44 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ORIENTATION_MATRIX_H
# define ORIENTATION_MATRIX_H

typedef struct s_matr
{
	double	a1;
	double	a2;
	double	a3;
	double	b1;
	double	b2;
	double	b3;
	double	c1;
	double	c2;
	double	c3;
}							t_matr;
#endif