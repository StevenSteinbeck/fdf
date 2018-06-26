# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stestein <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/10 12:53:41 by stestein          #+#    #+#              #
#    Updated: 2018/06/25 18:04:23 by stestein         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MLX_BASEDIR = ./minilibx/
MLX = $(addprefix $(MLX_BASEDIR), minilibx_macos_sierra)

NAME = fdf
SRCS_DIR = ./srcs/
INCLUDES = ./includes/
RM = /bin/rm -f

FILES = main read_utils matrix_utils prep_xform_matrices fdf_render image\
mouse_hooks key_hooks color info_window
CFILES = $(patsubst %, $(SRCS_DIR)%.c, $(FILES))
OFILES = $(patsubst %, %.o, $(FILES))
CFLAGS = -Wall -Wextra -Werror

MLX_LIB	= $(addprefix $(MLX), mlx.a)
MLX_INC = -I $(MLX)
MLX_LINK = -L $(MLX) -l mlx -framework OpenGL -framework AppKit

LFT = ./libft/
LFT_LIB = $(addprefix $(LFT), ft.a)
LFT_INC = -I $(LFT)includes/
LFT_LINK = -L $(LFT) -l ft

.PHONY: all clean fclean re

all: $(MLX_LIB) $(LFT_LIB) $(NAME)

$(OFILES):
	gcc $(CFLAGS) -c -I$(INCLUDES) $(MLX_INC) $(LFT_INC) $(CFILES)

$(LFT_LIB):
	make -C $(LFT)

$(MLX_LIB):
	make -C $(MLX)

$(NAME): $(OFILES)
	gcc $(CFLAGS) $(OFILES) $(MLX_LINK) $(LFT_LINK) -o $(NAME)

clean:
	make -C $(MLX) clean
	make -C $(LFT) clean
	$(RM) $(OFILES)

fclean: clean
	make -C $(LFT) fclean
	$(RM) $(NAME)

re: fclean all
