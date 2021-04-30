/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 10:54:41 by eriling           #+#    #+#             */
/*   Updated: 2021/04/30 15:47:00 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"
#include <mlx.h>

int	main(int ac, char **av)
{
	int	fd;

	if (ac == 2 && ft_strcmp(".rt", &av[1][ft_strlen(av[1]) - 3]) == 0)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			printf("Error: No file\n");
			return (1);
		}
		file_rt(fd, WINDOW);
	}
	else if (ac == 3 && ft_strcmp(".rt", &av[1][ft_strlen(av[1]) - 3]) == 0
		&& ft_strcmp("-save", av[2]) == 0)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			printf("Error: No file\n");
			return (1);
		}
		file_rt(fd, SAVE);
	}
	else
		printf("Error\nInput false");
	return (0);
}
