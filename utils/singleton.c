/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:53:45 by eriling           #+#    #+#             */
/*   Updated: 2021/02/18 17:11:52 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"
#include "libft.h"

t_all	*singleton(void)
{
	static t_all	*all = NULL;

	if (all)
		return (all);
	all = ft_calloc(sizeof(t_all), 1);
	return (all);
}
