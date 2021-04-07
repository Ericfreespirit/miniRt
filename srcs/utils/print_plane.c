/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 10:41:49 by eriling           #+#    #+#             */
/*   Updated: 2021/04/07 10:24:47 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "libft.h"

void	print_plane(size_t i)
{
	printf("#%zu Plane ", i);
	printf("%f,%f,%f| ", sg_dyn()->obj[i]->u.plane.x,
		sg_dyn()->obj[i]->u.plane.y, sg_dyn()->obj[i]->u.plane.z);
	printf("%f,%f,%f| ", sg_dyn()->obj[i]->u.plane.orien_x,
		sg_dyn()->obj[i]->u.plane.orien_y, sg_dyn()->obj[i]->u.plane.orien_z);
	printf("%d,%d,%d \n", sg_dyn()->obj[i]->u.plane.r,
		sg_dyn()->obj[i]->u.plane.g, sg_dyn()->obj[i]->u.plane.b);
}
