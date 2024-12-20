# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soujaour <soujaour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/11 15:27:14 by soujaour          #+#    #+#              #
#    Updated: 2024/12/14 22:16:14 by soujaour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = 1main.c 2checks.c 3render.c 4events.c 5utils1.c 5utils2.c 6ship.c
OBJS = $(SRCS:.c=.o)
LIBS = ./libft/libft.a ./printf/libftprintf.a ./minilibx_opengl_20191021/libmlx.a

$(NAME) : $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) $^ $(LIBS) -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c header.h
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBS) : ./libft/libft.h ./printf/ft_printf.h ./minilibx_opengl_20191021/mlx.h
	make -C ./libft
	make -C ./printf
	make -C ./minilibx_opengl_20191021
	
all : $(NAME)

clean :
	make -C ./libft clean
	make -C ./printf clean
	make -C ./minilibx_opengl_20191021 clean
	rm -rf $(OBJS)

fclean : clean
	make -C ./libft fclean
	make -C ./printf fclean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean
