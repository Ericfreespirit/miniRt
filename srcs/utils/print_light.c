/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 09:12:08 by eriling           #+#    #+#             */
/*   Updated: 2021/02/18 17:05:03 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"

void	print_light(size_t i)
{
	printf("#%zu Light ", i);
	printf("%f,%f,%f| ", sg_dyn()->obj[i]->u.light.x,
		sg_dyn()->obj[i]->u.light.y, sg_dyn()->obj[i]->u.light.z);
	printf("%f| ", sg_dyn()->obj[i]->u.light.rat_l);
	printf("%d,%d,%d \n", sg_dyn()->obj[i]->u.light.r,
		sg_dyn()->obj[i]->u.light.g, sg_dyn()->obj[i]->u.light.b);
}
