# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eriling <eriling@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/27 10:54:58 by eriling           #+#    #+#              #
#    Updated: 2021/04/29 15:58:17 by eriling          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = miniRT
CC = clang
HEAD = -Iinclude -Ilibft -Iminilibx-linux 
CFLAGS = -Wall -Wextra $(DEBUG)
#DEBUG = -fsanitize=address -g3

FILES = main.c file_rt.c parse.c parse_resolution.c parse_ambient.c \
			parse_camera.c parse_light.c parse_sphere.c parse_plane.c \
			parse_square.c parse_cylinder.c parse_triangle.c is_single_data.c is_mult_data.c \
			add_rgb.c add_3_float.c mlx_function.c comput_all_cam_view.c hit_sphere.c ray.c \
			singleton.c sg_dyn.c dynarr_cpy.c dynarr_new.c dynarr_push.c dynarr_realloc.c \
			print_struct.c print_dynarr.c print_camera.c print_light.c print_sphere.c print_plane.c \
			print_square.c print_cylinder.c print_triangle.c dynarr_freeall.c hook_function.c ft_abs.c \
			rgb_to_int.c vect_comput.c my_mlx_pixel_put.c comput_color.c comput_ray.c comput_light.c \
			vect_obj.c vect_operator.c matrix.c rgb_comput.c hit_plane.c check_end_element.c \
			ft_isspace.c vect_orien.c comput_triangle.c hit_triangle.c comput_rot_axis.c \
			hit_square.c hit_cylinder.c comput_cylinder.c create_bmp.c

SRC_PATH = $(shell find srcs -type d)
vpath %.c $(foreach dir, $(SRC_PATH), $(dir))

OBJ_PATH = objs
OBJ = $(addprefix $(OBJ_PATH)/, $(FILES:%.c=%.o))

all :   $(NAME) 

$(NAME) : libft/libft.a $(OBJ_PATH) $(OBJ) ./include/miniRT.h
	$(CC) -lXext -lX11 -lm $(CFLAGS) $(HEAD) $(OBJ) minilibx-linux/libmlx.a libft/libft.a -o ${NAME}
		
libft/libft.a : 
	make -C libft

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o : %.c
	$(CC) $(CFLAGS) $(HEAD) -c $< -o $@

print:
	@echo $(OBJ)
clean:
	rm -rf $(OBJ)
	make -C libft clean

fclean: clean
	rm -rf $(NAME)
	make -C libft fclean
re: fclean all
