/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_triangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 13:25:38 by eriling           #+#    #+#             */
/*   Updated: 2021/02/18 17:08:21 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "libft.h"

void	print_triangle(size_t i)
{
	printf("#%zu Triangle ", i);
	printf("%f,%f,%f| ", sg_dyn()->obj[i]->u.triangle.x_1,
		sg_dyn()->obj[i]->u.triangle.y_1, sg_dyn()->obj[i]->u.triangle.z_1);
	printf("%f,%f,%f| ", sg_dyn()->obj[i]->u.triangle.x_2,
		sg_dyn()->obj[i]->u.triangle.y_2, sg_dyn()->obj[i]->u.triangle.z_2);
	printf("%f,%f,%f| ", sg_dyn()->obj[i]->u.triangle.x_3,
		sg_dyn()->obj[i]->u.triangle.y_3, sg_dyn()->obj[i]->u.triangle.z_3);
	printf("%d,%d,%d \n", sg_dyn()->obj[i]->u.triangle.r,
		sg_dyn()->obj[i]->u.triangle.g, sg_dyn()->obj[i]->u.triangle.b);
}
