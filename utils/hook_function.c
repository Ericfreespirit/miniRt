/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 09:02:13 by eriling           #+#    #+#             */
/*   Updated: 2021/03/17 09:12:33 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"
#include <mlx.h>

int	red_cross(int key)
{
	exit(0);
	return (key);
}

int	switch_rt(int key, t_vars *vars, t_data *img)
{
	if (key == 65307)
	{
		(void)vars;
		(void)img;
		exit(0);
	}
	return (key);
}
