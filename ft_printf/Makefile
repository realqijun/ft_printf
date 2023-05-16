# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qang <qang@student.42kl.edu.my>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 09:14:26 by qang              #+#    #+#              #
#    Updated: 2023/05/16 11:00:20 by qang             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

srcs = ft_printf.c \
	   ft_putnbrs.c \
	   ft_putchars.c \
	   ft_putui.c \
	   ft_printaddr.c \
	   ft_puthex.c \
	   ft_puthex2.c

objs = $(srcs:.c=.o)

NAME = libftprintf.a
cflags = -Wall -Wextra -Werror
archive = ar -rc

all: $(NAME)

$(NAME): $(objs) ft_printf.h
	$(archive) $(NAME) $(objs)

clean:
	rm -rf $(objs)

fclean: clean
	rm -rf $(NAME)

%.o: %.c
	cc $(cflags) -c $^ -o $@

bonus: $(NAME)
