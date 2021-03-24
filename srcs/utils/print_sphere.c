/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 09:31:52 by eriling           #+#    #+#             */
/*   Updated: 2021/02/18 17:06:24 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "libft.h"

void	print_sphere(size_t i)
{
	printf("#%zu Sphere ", i);
	printf("%f,%f,%f| ", sg_dyn()->obj[i]->u.sphere.x,
		sg_dyn()->obj[i]->u.sphere.y, sg_dyn()->obj[i]->u.sphere.z);
	printf("%f| ", sg_dyn()->obj[i]->u.sphere.diam);
	printf("%d,%d,%d \n", sg_dyn()->obj[i]->u.sphere.r,
		sg_dyn()->obj[i]->u.sphere.g, sg_dyn()->obj[i]->u.sphere.b);
}
