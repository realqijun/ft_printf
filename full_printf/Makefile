# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qang <qang@student.42kl.edu.my>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 11:54:32 by qang              #+#    #+#              #
#    Updated: 2023/05/13 15:27:07 by qang             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
cflags = -Wall -Wextra -Werror
srcs = ft_putchars.c \
	   ft_putnbr.c \
	   ft_puthexs.c \
	   ft_printaddr.c \
	   ft_printf.c \
	   ft_putui.c

objs = $(srcs:.c=.o)

%.o: %.c
	cc $(cflags) -c $(@:.o=.c) -o $@

$(NAME): $(objs) ft_printf.h
	ar rc $(NAME) $(objs)

all: $(NAME)

clean:
	rm -rf $(objs)

fclean: clean
	rm -rf $(NAME)
