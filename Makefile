# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/25 20:56:19 by bjebedia          #+#    #+#              #
#    Updated: 2020/10/29 23:35:56 by bjebedia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := cub3D

CUB_SRC := cub3d.c ft_col_ceiling.c \
ft_col_floor.c ft_darken.c ft_draw_everything.c \
ft_farthest_wall.c ft_finish.c ft_image_switcher.c \
ft_init_win.c ft_key_actions.c ft_key_press.c \
ft_key_unpress.c ft_put_texture_on_wall.c \
ft_put_texture_on_wall2.c ft_rays.c ft_reset_sprites.c \
ft_screenshot.c ft_sprite.c ft_sprite2.c \
ft_sprite_init.c ft_sprite_prescan.c \
ft_walls.c ft_walls2.c ft_walls3.c \
ft_where_am_i.c \
validate/ft_who_is_absent.c validate/ft_check_position.c \
validate/ft_validate.c validate/ft_trash.c \
validate/ft_set_all_zero.c validate/ft_the_line.c \
validate/ft_borders.c validate/ft_map.c \
validate/ft_check_map2.c validate/ft_check_c.c \
validate/ft_check_ea.c validate/ft_check_f.c \
validate/ft_check_map.c validate/ft_check_no.c \
validate/ft_check_r.c validate/ft_check_s.c \
validate/ft_check_so.c validate/ft_check_we.c \
validate/ft_skip_spaces.c validate/ft_skip_spaces2.c \
validate/ft_check_map3.c validate/ft_resolution.c \
validate/ft_definetype2.c validate/ft_definetype.c \
validate/gnl/get_next_line.c validate/gnl/get_next_line_utils.c

HEADER := src/cub3d.h src/validate/validate.h src/validate/gnl/get_next_line.h

OBJ := $(CUB_SRC:%.c= src/%.o)

MLX_DIR = minilibx
FT_DIR = libft
MLX_LIB = $(MLX_DIR)/libmlx.a
FT_LIB = $(FT_DIR)/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -O0
LDFLAGS = -lm -L$(MLX_DIR) -lmlx -L$(FT_DIR) -lft -lXext -lX11

all: libft mlx $(NAME)

libft:
	@$(MAKE) -C libft/

mlx:
	@$(MAKE) -C $(MLX_DIR)

$(NAME): $(MLX_LIB) $(FT_LIB) $(OBJ) $(HEADER)
	@$(CC) $(OBJ) $(LDFLAGS) -o $@
	@echo "$(NAME) has been compiled"

%.o: %.c
	@$(CC) -c $< $(CFLAGS) -o $@
	@echo "$@ has been compiled"

clean:
	@rm -rf $(OBJ)
	@echo "Object files has been deleted"
	@$(MAKE) clean -C libft/
	@$(MAKE) clean -C minilibx/

fclean: clean
	@rm -rf $(NAME)
	@echo "$(NAME) has been deleted"
	@$(MAKE) fclean -C libft/
	@$(MAKE) clean -C minilibx/

re: fclean all

.PHONY: all libft bonus clean fclean re
