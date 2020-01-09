# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smaniani <smaniani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/27 13:44:06 by smaniani          #+#    #+#              #
#    Updated: 2020/01/08 09:21:14 by smaniani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3D
SRC		=	*.c
OBJ		=	$(SRC:.c=.o)

all		:	$(NAME)
$(NAME) :
		gcc  -Wall -Wextra $(SRC) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
clean	:
		rm -f *.o
fclean	: clean
		rm -f $(NAME)
re		: fclean
		make all
bonus	: re
