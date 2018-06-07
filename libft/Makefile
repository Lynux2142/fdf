# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lguiller <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 11:15:29 by lguiller          #+#    #+#              #
#    Updated: 2018/03/20 15:09:02 by lguiller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##################
##  VARIABLES   ##
##################

NAME	= libft.a
SRC		= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c \
		  ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
		  ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
		  ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c \
		  ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
		  ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c \
		  ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
		  ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
		  ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
		  ft_strsplit.c ft_itoa.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		  ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
		  ft_lstmap.c ft_putaddr.c ft_putaddr_fd.c ft_itoa_base.c ft_brackets.c \
		  ft_putnbr_base.c ft_isprime.c ft_abs.c ft_strcspn.c ft_pgcd.c ft_ppcm.c \
		  ft_realloc.c ft_sqrt.c get_next_line.c ft_isspace.c print_memory.c \
		  ft_atoi_base.c ft_power.c ft_split_whitespaces.c ft_error.c
OBJ		= $(SRC:.c=.o)
FLAGS	= -Wall -Wextra -Werror -O2

##################
##    COLORS    ##
##################

_GREY		= "\033[30m"
_RED		= "\033[31m"
_GREEN		= "\033[32m"
_YELLOW		= "\033[33m"
_BLUE		= "\033[34m"
_PURPLE		= "\033[35m"
_CYAN		= "\033[36m"
_WHITE		= "\033[37m"
_END		= "\033[0m"
_BOLD		= "\033[1m"
_CLEAR		= "\033[2K"
_SAVE		= "\033[7"
_BACK		= "\033[8"
_HIDE_CURS	= "\033[?25l"
_SHOW_CURS	= "\033[?25h"
_UP			= "\033[A"
_CUT		= "\033[k"

##################
##   TARGETS    ##
##################

.PHONY: all clean fclean re lynux booh

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo $(_CLEAR)$(_YELLOW)"building - "$(_GREEN)"libft"$(_END)
	@echo $(_GREEN)"Done."$(_END)$(_SHOW_CURS)

%.o: %.c
	@gcc $(FLAGS) -c $^ -o $@
	@echo $(_HIDE_CURS)$(_CLEAR)$(_YELLOW)"building - "$(_GREEN)$@$(_END)
	@printf $(_UP)$(_CUT)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

lynux:
	@echo "   /&& /&&   /&&                                              "
	@echo "  / &&/ &&  | &&                                              "
	@echo " /&&&&&&&&&&| &&       /&&   /&& /&&&&&&&  /&&   /&& /&&   /&&"
	@echo "|   &&  &&_/| &&      | &&  | &&| &&__  &&| &&  | &&|  && /&&/"
	@echo " /&&&&&&&&&&| &&      | &&  | &&| &&  \ &&| &&  | && \  &&&&/ "
	@echo "|_  &&  &&_/| &&      | &&  | &&| &&  | &&| &&  | &&  >&&  && "
	@echo "  | &&| &&  | &&&&&&&&|  &&&&&&&| &&  | &&|  &&&&&&/ /&&/\  &&"
	@echo "  |__/|__/  |________/ \____  &&|__/  |__/ \______/ |__/  \__/"
	@echo "                       /&&  | &&                              "
	@echo "                      |  &&&&&&/                              "
	@echo "                       \______/                               "

booh:
	@echo ""
	@echo "                           oooo############oooo"
	@echo "                       oo########################o"
	@echo "                   oo##############################o         o#   ## o# "
	@echo "   o # oo        o####################################o       ## ## ##o# "
	@echo "oo # #  #      o#########    #############    #########o       ###o##o# "
	@echo " ######o#     o#########      ###########      ##########o    ######## "
	@echo "  #######    ###########      ###########      ####################### "
	@echo "  #######################    #############    ##############     ### "
	@echo "     ###    #################################################      ### "
	@echo "     ###   o##################################################      ###o"
	@echo "    o##    ###################################################       ###o"
	@echo "    ###    #############################################   ######ooooo####o"
	@echo "   o###oooo#####  #####################################   o################# "
	@echo "   ######## ####   ##################################     ####        "
	@echo "             ####     ############################       o### "
	@echo "              ###o        ################## ##          ### "
	@echo "               ###o           ##  ######               o### "
	@echo "                ####o                                o### "
	@echo "                  ####o      o######o ####o        o#### "
	@echo "                    #####oo       ####o#####o   o#### "
	@echo "                        #####oooo   ###o#########   "
	@echo "                           #######oo ########## "
	@echo "                                     ########### "
	@echo "                                     ############ "
	@echo "                                      ########## "
	@echo "                                       ######## "
