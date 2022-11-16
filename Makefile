# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 12:01:18 by cmansey           #+#    #+#              #
#    Updated: 2022/11/16 14:01:49 by cmansey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
ft_strchr.c ft_strlen.c ft_putnbru_fd.c ft_intlen_hexa.c ft_intlen_id.c \
ft_intlen_u.c ft_print_hexa.c ft_print_p.c ft_search_arg_1.c ft_search_arg_2.c \
ft_search_arg_3.c

all: $(NAME)

OBJS = $(SRCS:.c=.o)

CC = gcc
RM = rm -f
AR = ar -rcs

CFLAGS = -Wall -Wextra -Werror

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
