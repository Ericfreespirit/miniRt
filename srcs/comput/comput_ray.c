/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comput_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:47:53 by eriling           #+#    #+#             */
/*   Updated: 2021/04/07 08:11:57 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "comput.h"
#include "struct.h"

t_vect	ray_dir_obj(t_vect v1, t_vect v2)
{
	t_vect	dir;

	dir = vect_sous(v1, v2);
	return (normalize(dir));
}

t_vect	ray_dir_cam(t_data img)
{
	t_vect	dir;

	dir.x = (img.x - (singleton()->r_x / 2)) * img.pixel_len;
	dir.y = ((singleton()->r_y / 2) - img.y) * img.pixel_len;
	dir.z = 1;
	return (normalize(dir));
}
