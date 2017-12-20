#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: gquesnot <gquesnot@student.le-101.fr>      +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2017/09/30 20:21:34 by gquesnot          #+#    #+#             *#
#*   Updated: 2017/10/16 16:12:24 by gquesnot         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME	= fillit

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -O3

INC		= -I ./libft/ -I ./includes/
LFLAGS	=  -L ./libft/ -lft

SRC_PATH = ./src/
SRCS	= ft_param.c \
			ft_tetris.c \
			ft_struct.c \
			main.c \
			tetris2.c \
			ft_check.c

OBJ_PATH = ./obj/
OBJS = $(SRCS:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRCS))
OBJ = $(addprefix $(OBJ_PATH),$(OBJS))

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LFLAGS)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
		rm -f $(OBJ)
		@rmdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null

fclean: clean
		rm -f $(NAME)

re: fclean all
