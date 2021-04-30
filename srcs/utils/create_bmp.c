/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 10:56:04 by eriling           #+#    #+#             */
/*   Updated: 2021/04/30 11:02:09 by eriling          ###   ########.fr       */
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
	t_header	head;

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

static	int	*fill_file(t_data img_scene)
{
	int	*file;
	int	i;
	int	j;
	int	k;

	file = ft_calloc(singleton()->r_y * singleton()->r_x, sizeof(int));
	if (file == NULL)
		return (NULL);
	j = 0;
	while (j < singleton()->r_y)
	{
		i = 0;
		while (i < singleton()->r_x)
		{
			k = (singleton()->r_y - 1 - j)
				* (img_scene.line_length) / 4 + i;
			file[k] = ((int *)img_scene.addr)
				[i + (j * (img_scene.line_length) / 4 )];
			i++;
		}
		j++;
	}
	return (file);
}

void	create_bmp(t_vars *vars)
{
	t_bmp	var;
	char	header[54];

	var.i = 0;
	while (var.i < (int)count_cam())
	{
		var.file_name = ft_itoa(var.i);
		var.tmp = var.file_name;
		var.file_name = ft_strjoin(var.file_name, ".bmp");
		free(var.tmp);
		var.fd = open(var.file_name, O_CREAT | O_WRONLY, 0666);
		create_header(&header[0]);
		var.file = (char*)fill_file(vars->array[var.i].img_scene);
		write(var.fd, header, 54);
		write(var.fd, var.file, 4 * singleton()->r_x * singleton()->r_y);
		free(var.file);
		free(var.file_name);
		var.i++;
	}
	free_program_bmp(vars);
	close(var.fd);
	exit(0);
}
