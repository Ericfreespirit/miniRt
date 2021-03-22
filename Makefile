# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eriling <eriling@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/27 10:54:58 by eriling           #+#    #+#              #
#    Updated: 2021/03/19 13:19:19 by eriling          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = miniRT
CC = clang
HEAD = -Iinclude -Ilibft -I../minilibx-linux
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

FILES = main.c \
				file_rt.c \

DIR_PARSE = parse/parse.c \
						parse/parse_resolution.c \
						parse/parse_ambient.c \
						parse/parse_camera.c \
						parse/parse_light.c \
						parse/parse_sphere.c \
						parse/parse_plane.c \
						parse/parse_square.c \
						parse/parse_cylinder.c \
						parse/parse_triangle.c \

DIR_IS = parse/is_/is_single_data.c \
						parse/is_/is_mult_data.c \

					

DIR_ADD = parse/add_/add_rgb.c \
					parse/add_/add_3_float.c \

DIR_DRAW =	comput/init_mlx_function.c \
						comput/comput.c \

DIR_UTILS = utils/singleton.c \
						utils/sg_dyn.c \
						utils/dynarr_cpy.c \
						utils/dynarr_new.c \
						utils/dynarr_push.c \
						utils/dynarr_realloc.c \
						utils/print_struct.c \
						utils/print_dynarr.c \
						utils/print_camera.c \
						utils/print_light.c \
						utils/print_sphere.c \
						utils/print_plane.c \
						utils/print_square.c \
						utils/print_cylinder.c \
						utils/print_triangle.c \
						utils/dynarr_freeall.c \
						utils/hook_function.c \
						utils/ft_abs.c \

 
OBJ = $(FILES:.c=.o) \
			$(DIR_PARSE:.c=.o) \
			$(DIR_IS:.c=.o) \
			$(DIR_ADD:.c=.o) \
			$(DIR_UTILS:.c=.o) \
			$(DIR_DRAW:.c=.o) \

all :   $(NAME) 

$(NAME) : libft/libft.a $(OBJ) ./include/miniRT.h
		$(CC) -lXext -lX11 $(CFLAGS) $(HEAD) $(OBJ) ../minilibx-linux/libmlx.a libft/libft.a -o ${NAME}
		
libft/libft.a : 
	make -C libft

.c.o: 
		$(CC) $(CFLAGS) $(HEAD) -c $< -o $@

clean:
	rm -rf $(OBJ)
	make -C libft clean

fclean: clean
	rm -rf $(NAME)
	make -C libft fclean
re: fclean all
