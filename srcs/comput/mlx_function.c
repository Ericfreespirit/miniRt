/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 08:27:08 by eriling           #+#    #+#             */
/*   Updated: 2021/03/24 11:32:46 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"
#include <mlx.h>

int	mlx_function(void)
{
	t_vars	vars;
	int		sizex;
	int		sizey;

	sizex = 0;
	sizey = 0;
	vars.mlx = mlx_init();
	mlx_get_screen_size(vars.mlx, &sizex, &sizey);
	if (singleton()->r_x > sizex)
		singleton()->r_x = sizex;
	if (singleton()->r_y > sizey)
		singleton()->r_y = sizey;
	vars.mlx_win = mlx_new_window(vars.mlx,
			singleton()->r_x, singleton()->r_y, "miniRT");
	vars.img.img = mlx_new_image(vars.mlx, singleton()->r_x, singleton()->r_y);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel,
			&vars.img.line_length, &vars.img.endian);
	comput(&vars.img, &vars);
	mlx_hook(vars.mlx_win, 33, 1L << 17, red_cross, &vars);
	mlx_hook(vars.mlx_win, 2, 1L << 0, switch_rt, &vars);
	mlx_loop(vars.mlx);
	return (0);
}