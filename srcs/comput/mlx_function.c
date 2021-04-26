/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 08:27:08 by eriling           #+#    #+#             */
/*   Updated: 2021/04/26 11:28:33 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"
#include "comput.h"
#include <mlx.h>

void		output(t_scene *array, int win_or_save, t_vars *vars)
{
	if (win_or_save == WINDOW)
	{
		vars->mlx_win = mlx_new_window(vars->mlx,
		singleton()->r_x, singleton()->r_y, "miniRT");
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, array[0].img_scene.img, 0, 0);
	}
	else if (win_or_save == SAVE)
			printf("no bmp file yet");
}


int	mlx_function(int win_or_save)
{
	t_vars	vars;
	int		sizex;
	int		sizey;
	t_scene array;

	sizex = 0;
	sizey = 0;
	vars.mlx = mlx_init();
	mlx_get_screen_size(vars.mlx, &sizex, &sizey);
	if (singleton()->r_x > sizex)
		singleton()->r_x = sizex;
	if (singleton()->r_y > sizey)
		singleton()->r_y = sizey;
	array = *comput_all_cam_view(&vars);
	output(&array, win_or_save, &vars);
	mlx_hook(vars.mlx_win, 12, 1L << 15, ft_image, &vars);
	mlx_hook(vars.mlx_win, 33, 1L << 17, red_cross, &vars);
	mlx_hook(vars.mlx_win, 2, 1L << 0, esc_rt, &vars);
	mlx_loop(vars.mlx);
	// ft_free_all_scene(array); 
	return (0);
}
