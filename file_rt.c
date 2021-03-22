/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:07:46 by eriling           #+#    #+#             */
/*   Updated: 2021/03/22 12:01:30 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"
#include <mlx.h>

int	error_parse(int error, int fd)
{
	if (error == 1)
	{
		printf("Error: bad parsing, check you value(s) or the format\n");
		free(singleton());
		dynarr_freeall();
		close(fd);
		return (1);
	}
	return (0);
}

int	min_data(void)
{
	if ((singleton()->r_x == 0 || singleton()->r_y == 0))
	{
		printf("Error: Resolution problem");
		return (1);
	}
	else if (singleton()->a == 0)
	{
		printf("Error: by default need Ambiente, Resolution and camera datas\n");
		printf("Miss Ambiente data");
		return (1);
	}
	return (0);
}

void	file_rt(int fd)
{
	int		ret;
	char	*line;
	int		error;

	error = 0;
	ret = 1;
	while (ret)
	{
		ret = get_next_line(fd, &line, 1);
		if (parse(line) == 1)
			error = 1;
		free(line);
		if (ret == 0)
			break ;
	}
	if (error_parse(error, fd) == 1)
		return ;
	else if (min_data() == 1)
		return ;
	close(fd);
	print_struct(); // delete at the end
	init_mlx_function();

	return ;
}
