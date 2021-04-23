/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynarr_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 10:41:51 by eriling           #+#    #+#             */
/*   Updated: 2021/04/23 12:05:13 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"

t_dyn	*dynarr_new(void)
{
	t_dyn	*arr;

	arr = malloc(sizeof(t_dyn));
	if (arr == NULL)
		return (NULL);
	arr->obj = malloc(sizeof (t_obj *) * 8);
	if (arr->obj == NULL)
	{
		free(arr);
		return (NULL);
	}
	arr->capacity = 8;
	arr->size = 0;
	return (arr);
}
