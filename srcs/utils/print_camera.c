/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:52:04 by eriling           #+#    #+#             */
/*   Updated: 2021/04/06 13:10:04 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"

void	print_camera(size_t i)
{
	printf("#%zu Camera ", i);
	printf("%f,%f,%f| ", sg_dyn()->obj[i]->u.camera.x,
		sg_dyn()->obj[i]->u.camera.y, sg_dyn()->obj[i]->u.camera.z);
	printf("%f,%f,%f| ", sg_dyn()->obj[i]->u.camera.orien_x,
		sg_dyn()->obj[i]->u.camera.orien_y, sg_dyn()->obj[i]->u.camera.orien_z);
	printf("%d\n", sg_dyn()->obj[i]->u.camera.fov);
}
