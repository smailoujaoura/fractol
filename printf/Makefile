NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
AR = ar rcs

SRCS = printf.c necessary.c functions.c extra.c
OBJS = $(SRCS:.c=.o)

%.o : %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus : all

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean