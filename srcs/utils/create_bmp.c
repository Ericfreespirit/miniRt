/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 10:56:04 by eriling           #+#    #+#             */
/*   Updated: 2021/04/29 16:25:07 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"
#include "comput.h"
#include <mlx.h>

void	free_program_bmp(t_vars *vars)
{
	int	i;

	i = 0;
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

static void	init_header(t_header *header)
{
	header->type = 0x4d42;
	header->size = 54 + 4 * singleton()->r_x * singleton()->r_y;
	header->start = 54;
	header->header_size = 40;
	header->planes = 1;
	header->bpp = 32;
	header->raw_size = 4 * singleton()->r_x * singleton()->r_y;
	header->res = 2835;
}

static void	create_header(char *header)
{
	t_header head;

	ft_bzero(header, 54);
	init_header(&head);
	ft_memcpy(&header[0], &head.type, 2);
	ft_memcpy(&header[2], &head.size, 4);
	ft_memcpy(&header[10], &head.start, 4);
	ft_memcpy(&header[14], &head.header_size, 4);
	ft_memcpy(&header[18], &singleton()->r_x, 4);
	ft_memcpy(&header[22], &singleton()->r_y, 4);
	ft_memcpy(&header[26], &head.planes, 2);
	ft_memcpy(&header[28], &head.bpp, 2);
	ft_memcpy(&header[34], &head.raw_size, 4);
	ft_memcpy(&header[38], &head.res, 4);
	ft_memcpy(&header[42], &head.res, 4);
}

static	int	*fill_file(t_vars *vars)
{
	int *file;
	int	i;
	int	j;
	int k;

	if (!(file = ft_calloc(singleton()->r_y * singleton()->r_x, sizeof(int))))
		return (NULL);
	j = 0;
	while (j < singleton()->r_y)
	{
		i = 0;
		while (i < singleton()->r_x)
		{
			k = (singleton()->r_y  - 1 - j)
			* (vars->array[0].img_scene.line_length) / 4 + i;
			file[k] = ((int *)vars->array[0].img_scene.addr)
			[i +(j * (vars->array[0].img_scene.line_length) / 4 )];
			i++;
		}
		j++;
	}
	return (file);
}

void	create_bmp(t_vars *vars)
{
	int	fd;
	int		i;
	char *file;
	char *file_name;
	char	header[54];

	i = 0;
	file_name = ft_strjoin(i,".bmp");

	fd = open("1.bmp", O_CREAT | O_WRONLY, 0666);
	create_header(&header[0]);
	file = (char*)fill_file(vars);
	write(fd, header, 54);
	write(fd, file, 4 * singleton()->r_x * singleton()->r_y);
	free_program_bmp(vars);
	free(file);
	close(fd);
	exit(0);
}
