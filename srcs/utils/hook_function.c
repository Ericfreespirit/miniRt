/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 09:02:13 by eriling           #+#    #+#             */
/*   Updated: 2021/04/27 11:01:45 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"
#include "comput.h"
#include <mlx.h>

void	free_program(t_vars *vars)
{
	int	i;

	i = 0;
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	while (i < (int)count_cam())
	{
		mlx_destroy_image(vars->mlx, vars->array[i].img_scene.img);
		i++;
	}
	mlx_destroy_display(vars->mlx);
	free(vars->array); 
	free(vars->mlx);
	free(singleton());
	dynarr_freeall();
}

int	red_cross(t_vars *vars)
{
	free_program(vars);
	exit(0);
}

int	key_press(int key, t_vars *vars)
{
	if (key == 65307)
	{
		free_program(vars);
		exit(0);
	}
	else if (key == 65361 && vars->i > 0) // left
	{
		vars->i -= 1;
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
		vars->array[vars->i].img_scene.img, 0, 0);
	}
	else if (key == 65363 && vars->i < (int)count_cam()-1) // right
	{
		vars->i += 1;
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
		vars->array[vars->i].img_scene.img, 0, 0);
	}
	return (key);
}

int	ft_image(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->mlx_win,
		vars->array[vars->i].img_scene.img, 0, 0);
	return (0);
}
