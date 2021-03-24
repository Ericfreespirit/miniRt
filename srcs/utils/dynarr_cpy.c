/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynarr_cpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 10:42:46 by eriling           #+#    #+#             */
/*   Updated: 2021/02/18 16:53:57 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"

void	dynarr_cpy(t_obj **dst, t_dyn *src)
{
	size_t	i;

	i = 0;
	while (i < src->size)
	{
		dst[i] = src->obj[i];
		i++;
	}
}
