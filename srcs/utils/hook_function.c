/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 09:02:13 by eriling           #+#    #+#             */
/*   Updated: 2021/04/08 09:00:14 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"
#include <mlx.h>

void	free_program(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free(singleton());
	dynarr_freeall();
}

int	red_cross(t_vars *vars)
{
	free_program(vars);
	exit(0);
}

int	switch_rt(int key, t_vars *vars)
{
	if (key == 65307)
	{
		free_program(vars);
		exit(0);
	}
	return (key);
}

int	put_image(t_vars *vars)
{
	//mlx_put_image_to_window(vars->mlx, vars->mlx_win, img->img, 0, 0);
	return (0);
}
