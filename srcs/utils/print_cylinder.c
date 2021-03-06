/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 11:33:49 by eriling           #+#    #+#             */
/*   Updated: 2021/04/07 10:25:50 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "libft.h"

void	print_cylinder(size_t i)
{
	printf("#%zu Cylinder ", i);
	printf("%f,%f,%f| ", sg_dyn()->obj[i]->u.cylinder.x,
		sg_dyn()->obj[i]->u.cylinder.y, sg_dyn()->obj[i]->u.cylinder.z);
	printf("%f,%f,%f| ", sg_dyn()->obj[i]->u.cylinder.orien_x,
		sg_dyn()->obj[i]->u.cylinder.orien_y, sg_dyn()->obj[i]->u.cylinder.orien_z);
	printf("%f| ", sg_dyn()->obj[i]->u.cylinder.diam);
	printf("%f| ", sg_dyn()->obj[i]->u.cylinder.high);
	printf("%d,%d,%d \n", sg_dyn()->obj[i]->u.cylinder.r,
	sg_dyn()->obj[i]->u.cylinder.g, sg_dyn()->obj[i]->u.cylinder.b);
}
