# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/29 18:50:32 by gmelissi          #+#    #+#              #
#    Updated: 2021/08/31 00:53:04 by gmelissi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

CC = gcc
PATH_SRC = ./srcs/
SRC = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
SRCS = $(addprefix $(PATH_SRC), $(SRC))
PATH_HEAD = ./includes/
HEAD = ft.h
HEADS = $(addprefix $(PATH_HEAD), $(HEAD))
FLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
NAME = libft.a

all: $(NAME)

.c.o:
	$(CC) $(FLAGS) -include $(HEADS) -c $*.c -o $*.o

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	
re: fclean all
