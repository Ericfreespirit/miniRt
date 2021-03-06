/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 08:27:08 by eriling           #+#    #+#             */
/*   Updated: 2021/05/03 09:59:36 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"
#include "comput.h"
#include <mlx.h>

static void	init_mlx_function_var(t_vars *vars, int *sizex, int *sizey)
{
	*sizex = 0;
	*sizey = 0;
	vars->i = 0;
	vars->mlx = mlx_init();
	mlx_get_screen_size(vars->mlx, sizex, sizey);
	if (singleton()->r_x > *sizex)
		singleton()->r_x = *sizex;
	if (singleton()->r_y > *sizey)
		singleton()->r_y = *sizey;
}

int	mlx_function(int win_or_save)
{
	t_vars	vars;
	int		sizex;
	int		sizey;

	init_mlx_function_var(&vars, &sizex, &sizey);
	vars.array = comput_all_cam_view(&vars);
	if (vars.array == NULL || count_cam() == 0)
	{
		printf("Error\nmalloc of the cam");
		free(vars.mlx);
		free(singleton());
		dynarr_freeall();
		return (0);
	}
	if (win_or_save == SAVE)
		create_bmp(&vars);
	vars.mlx_win = mlx_new_window(vars.mlx,
			singleton()->r_x, singleton()->r_y, "miniRT");
	mlx_hook(vars.mlx_win, 12, 1L << 15, ft_image, &vars);
	mlx_hook(vars.mlx_win, 33, 1L << 17, red_cross, &vars);
	mlx_hook(vars.mlx_win, 2, 1L << 0, key_press, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
