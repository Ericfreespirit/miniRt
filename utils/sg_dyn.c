/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sg_dyn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 08:34:22 by eriling           #+#    #+#             */
/*   Updated: 2021/02/18 17:11:00 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"
#include "libft.h"

t_dyn	*sg_dyn(void)
{
	static t_dyn	*obj = NULL;

	if (obj)
		return (obj);
	else
		obj = dynarr_new();
	return (obj);
}
