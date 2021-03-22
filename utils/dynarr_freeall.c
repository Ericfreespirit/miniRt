/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynarr_freeall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 14:28:58 by eriling           #+#    #+#             */
/*   Updated: 2021/03/22 11:37:29 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"

void	dynarr_freeall(void)
{
	size_t	i;

	i = 0;
	if (sg_dyn() != NULL)
	{
		while (i < sg_dyn()->size)
		{
			free(sg_dyn()->obj[i]);
			i++;
		}
		free(sg_dyn()->obj);
		free(sg_dyn());
	}
}
