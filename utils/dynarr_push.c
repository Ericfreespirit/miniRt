/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynarr_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 10:44:58 by eriling           #+#    #+#             */
/*   Updated: 2021/02/18 16:55:35 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"

int	dynarr_push(t_dyn *arr, t_obj *obj)
{
	if (arr->size == arr->capacity && dynarr_realloc(arr) < 0)
		return (-1);
	arr->obj[arr->size++] = obj;
	return (0);
}
