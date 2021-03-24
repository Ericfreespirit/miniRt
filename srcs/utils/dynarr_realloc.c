/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynarr_realloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 10:44:28 by eriling           #+#    #+#             */
/*   Updated: 2021/02/18 16:55:46 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"

int	dynarr_realloc(t_dyn *arr)
{
	size_t	new_cap;
	t_obj	**new_obj;

	new_cap = arr->capacity * 2;
	new_obj = malloc(sizeof(t_obj *) * new_cap);
	if (new_obj == NULL)
		return (-1);
	dynarr_cpy(new_obj, arr);
	free(arr->obj);
	arr->obj = new_obj;
	arr->capacity = new_cap;
	return (0);
}
