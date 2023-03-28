# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 07:25:34 by aandom            #+#    #+#              #
#    Updated: 2023/03/11 22:08:31 by aandom           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRCS = complex.c julia.c utils.c zoom_key.c drawfractal.c set_window.c fractal.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wextra -Werror -Wall 
CC = gcc -fsanitize=address
LINKER = -Lmlx -lmlx -framework OpenGL -framework AppKit

$(NAME): $(OBJS)
		 $(MAKE) -C mlx
		 $(CC) $(CFLAGS) $(OBJS) $(LINKER) -o $(NAME)

all: $(NAME)

clean:	
		$(MAKE) clean -C mlx
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re:	fclean	$(NAME)

.PHONY: all clean fclean re