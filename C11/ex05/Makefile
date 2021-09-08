# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/01 23:14:14 by gmelissi          #+#    #+#              #
#    Updated: 2021/09/01 23:24:02 by gmelissi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean

CC = gcc
PATH_SRC = ./
SRC = do-op.c ft_funcs.c ft_io.c ft_ops.c
SRCS = $(addprefix $(PATH_SRC), $(SRC))
PATH_HEAD = ./
HEAD = ft_funcs.h ft_io.h ft_ops.h
HEADS = $(addprefix $(PATH_HEAD), $(HEAD))
FLAGS = -Wall -Wextra -Werror
NAME = do-op
OBJS = $(SRCS:.c=.o)
	
all: $(NAME)

$(NAME): 
	$(CC) $(FLAGS) -include $(HEADS) -c $(SRCS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	rm -f *.o *.gch $(NAME)
