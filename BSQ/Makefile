# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmelissi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/09 00:08:51 by gmelissi          #+#    #+#              #
#    Updated: 2021/09/09 00:10:42 by gmelissi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
HEADER = ft_str.h ft_valid.h t_file.h t_map.h t_map_props.h t_solve.h
FLAG = -Wall -Wextra -Werror
OPTION = $(HEADER)
SRC = bsq.c ft_str.c t_file.c t_map_get_set.c t_map_props_get.c t_map_props_set.c t_map_props.c t_map.c ft_valid.c t_solve.c
OBJ = $(SRC:.c=.o)
all: $(NAME)
.c.o:
	gcc $(FLAG) -c $< -o ${<:.c=.o}
$(NAME): $(OBJ)
	gcc $(FLAG) -o $(NAME) $(OBJ)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
