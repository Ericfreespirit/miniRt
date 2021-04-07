/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:49:38 by eriling           #+#    #+#             */
/*   Updated: 2021/04/07 11:48:57 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"
#include "print_struct.h"

void	print_struct(void)
{
	printf("Resolution ");
	printf("%d ", singleton()->r_x);
	printf("%d\n", singleton()->r_y);
	printf("Ambient ");
	printf("%f ", singleton()->a_ran_light);
	printf("%d,", singleton()->a_r);
	printf("%d,", singleton()->a_g);
	printf("%d\n", singleton()->a_b);
	print_dynarr();
}

void	print_vector(t_vect v)
{
	printf("v.x = %f| v.y = %f | v.z = %f\n", v.x, v.y, v.z);
}
