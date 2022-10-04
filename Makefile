# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hferjani <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 14:48:07 by hferjani          #+#    #+#              #
#    Updated: 2022/10/03 15:06:40 by hferjani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc -g3

CFLAGS = -Wall -Werror -Wextra

SRC = Main.c	\
	operations.c	\
	operations_utils.c	\
	parsing_and_errors.c	\
	radix_sort.c	\
	sort_5_and_less.c	\
	test_index.c	\
	utils.c	\
	utils_2.c

HEADER = push_swap.h

OBJ = $(SRC:.c=.o)

all: $(NAME) 

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

test3:
	$(eval ARG = $(shell shuf -i 0-100 -n 3)) 
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Nombre d'opérations : "
	@./push_swap $(ARG) | wc -l

test5:
	$(eval ARG = $(shell shuf -i 0-5000 -n 5))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Nombre d'opérations : "
	@./push_swap $(ARG) | wc -l

test100:
	$(eval ARG = $(shell shuf -i 0-100 -n 100))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Nombre d'opérations : "
	@./push_swap $(ARG) | wc -l

stest6:
	$(eval ARG = $(shell shuf -i 0-5000 -n 6))
	./push_swap $(ARG)

stest500:
	$(eval ARG = $(shell shuf -i 0-5000 -n 500))
	./push_swap $(ARG) | ./checker $(ARG)

test500:
	$(eval ARG = $(shell shuf -i 0-5000 -n 500))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Nombre d'opérations : "
	@./push_swap $(ARG) | wc -l

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test3 test5 test500 stest6 stest500 test100
