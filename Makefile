# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: habouda <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/31 12:40:07 by habouda           #+#    #+#              #
#    Updated: 2024/06/04 14:48:09 by habouda          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COMPIL #####################################################################

CC = cc 
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

### SRCS #######################################################################

SRCS = ft_hexa.c \
		ft_pointer.c \
		ft_printf.c \
		ft_putchar.c \
		ft_putnbr.c \
		ft_putstr.c \
		ft_strlen.c \

### OBJS #######################################################################

OBJS = $(SRCS:.c=.o)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

### RULES #######################################################################

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re: 
	fclean all

.PHONY : re fclean all make