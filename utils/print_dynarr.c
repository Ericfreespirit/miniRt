/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dynarr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:51:27 by eriling           #+#    #+#             */
/*   Updated: 2021/03/22 11:34:37 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"

void	print_dynarr(void)
{
	size_t	i;

	i = 0;
	while (i < sg_dyn()->size)
	{
		if (sg_dyn()->obj[i]->my_type == camera)
			print_camera(i);
		else if (sg_dyn()->obj[i]->my_type == light)
			print_light(i);
		else if (sg_dyn()->obj[i]->my_type == sphere)
			print_sphere(i);
		else if (sg_dyn()->obj[i]->my_type == plane)
			print_plane(i);
		else if (sg_dyn()->obj[i]->my_type == square)
			print_square(i);
		else if (sg_dyn()->obj[i]->my_type == cylinder)
			print_cylinder(i);
		else if (sg_dyn()->obj[i]->my_type == triangle)
			print_triangle(i);
		i++;
	}
}
