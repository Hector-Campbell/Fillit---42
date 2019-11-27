# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/09 06:07:10 by vdauverg          #+#    #+#              #
#    Updated: 2019/08/12 22:04:33 by hecampbe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
C_FILES = functionality.c block_check.c map_check.c process_input.c read_input.c iteration.c fillit.c
O_FILES = functionality.o block_check.o map_check.o process_input.o read_input.o iteration.o fillit.o
FLAGS = -Wall -Wextra -Werror

$(NAME): $(O_FILES)
	gcc $(O_FILES) libft/libft.a -o $(NAME)

$(O_FILES): $(C_FILES)
	gcc $(FLAGS) -c $(C_FILES)

all: $(NAME)

clean:
	rm -f $(O_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
