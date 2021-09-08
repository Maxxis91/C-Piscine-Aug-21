# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/31 23:05:08 by gmelissi          #+#    #+#              #
#    Updated: 2021/08/31 23:05:50 by gmelissi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean

CC = gcc
PATH_SRC = ./
SRC = ft_tail.c ft_err.c
SRCS = $(addprefix $(PATH_SRC), $(SRC))
PATH_HEAD = ./
HEAD = ft_err.h
HEADS = $(addprefix $(PATH_HEAD), $(HEAD))
FLAGS = -Wall -Wextra -Werror
NAME = ft_tail
OBJS = $(SRCS:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(FLAGS) -include $(HEADS) -c $*.c -o $*.o

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $^ -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
