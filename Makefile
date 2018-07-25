# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/16 12:18:12 by lguiller          #+#    #+#              #
#    Updated: 2018/07/25 19:36:31 by lguiller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##################
##  VARIABLES   ##
##################

OPE_SYS			= $(shell uname)
NAME			= fdf
SRCS			= main.c ft_check_stock.c ft_list.c ft_draw.c \
				  event_functions.c ft_pixels.c octan_part_one.c \
				  octan_part_two.c octan_part_three.c octan_part_four.c \
				  auto_function.c
MINILIBX		= $(MLX_DIR)/libmlx.a
LIBFT			= libft/libft.a
OBJ				= $(addprefix ./srcs/, $(SRCS:.c=.o))
FLAGS			= -Wall -Wextra -Werror -O2

ifeq ($(OPE_SYS), Linux)
	INCLUDES	= -I includes -I libft -I minilibx_x11 -I /usr/include
	MLX_DIR		= minilibx_x11
	FRAMEWORK	= -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm
else
	INCLUDES	= -I includes -I libft -I minilibx
	MLX_DIR		= minilibx
	FRAMEWORK	= -framework OpenGL -framework Appkit
endif

##################
##    COLORS    ##
##################

_BLACK	= "\033[30m"
_RED	= "\033[31m"
_GREEN	= "\033[32m"
_YELLOW	= "\033[33m"
_BLUE	= "\033[34m"
_VIOLET	= "\033[35m"
_CYAN	= "\033[36m"
_WHITE	= "\033[37m"
_END	= "\033[0m"
_CLEAR	= "\033[2K"
_UP		= "\033[A"
_CUT	= "\033[k"

##################
##   TARGETS    ##
##################

.PHONY: all libft minilibx clean fclean re

all: $(NAME)

libft:
	@make -sC libft

minilibx: libft
	@make -sC $(MLX_DIR)

$(NAME):  minilibx $(OBJ)
	@gcc $(FLAGS) $(OBJ) $(LIBFT) $(FRAMEWORK) $(MINILIBX) -o $(NAME)
	@echo $(_GREEN)"Done."$(_END)

%.o: %.c
	@gcc $(FLAGS) $(INCLUDES) -c $^ -o $@
	@printf $(_YELLOW)"building - "$(_GREEN)
	@printf $@ | cut -c6- | cut -d'.' -f1
	@printf $(_END)

clean:
	@make -sC libft clean
	@make -sC $(MLX_DIR) clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@make -sC libft fclean
	@/bin/rm -f $(NAME)

re:
	@$(MAKE) -s fclean
	@$(MAKE) -s

lynux:
	@make -sC libft lynux

booh:
	@make -sC libft booh
