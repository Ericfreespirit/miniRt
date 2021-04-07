/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 11:25:13 by eriling           #+#    #+#             */
/*   Updated: 2021/04/07 10:25:21 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "libft.h"

void	print_square(size_t i)
{
	printf("#%zu Square ", i);
	printf("%f,%f,%f| ", sg_dyn()->obj[i]->u.square.x,
		sg_dyn()->obj[i]->u.square.y, sg_dyn()->obj[i]->u.square.z);
	printf("%f,%f,%f| ", sg_dyn()->obj[i]->u.square.orien_x,
		sg_dyn()->obj[i]->u.square.orien_y, sg_dyn()->obj[i]->u.square.orien_z);
	printf("%f| ", sg_dyn()->obj[i]->u.square.high);
	printf("%d,%d,%d \n", sg_dyn()->obj[i]->u.square.r,
		sg_dyn()->obj[i]->u.square.g, sg_dyn()->obj[i]->u.square.b);
}
