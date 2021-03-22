/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 10:54:41 by eriling           #+#    #+#             */
/*   Updated: 2021/03/22 09:40:59 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"
#include <../minilibx-linux/mlx.h>


int	main(int ac, char **av)
{
	int	fd;

	if (ac == 2 && ft_strcmp(".rt", &av[1][ft_strlen(av[1]) - 3]) == 0)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (1);
		file_rt(fd);
	}
	else if (ac == 3 && ft_strcmp(".rt", &av[1][ft_strlen(av[1]) - 3]) == 0
		&& ft_strcmp("-save", av[2]) == 0)
	{
		printf("save image in bmp format\n");
	}
	else
		printf("Error\n");
	return (0);
}
