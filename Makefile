# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/01 16:19:39 by daniefe2          #+#    #+#              #
#    Updated: 2025/03/19 14:06:26 by daniefe2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Paths
PRINTF_DIR = lib/ft_printf
LIBFT_DIR = lib/Libft
# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -I./headers
# Libraries
PRF = -L $(PRINTF_DIR) -lftprintf
LIB = -L $(LIBFT_DIR) -lft
# Source files
SRCS =	sources/main.c \
		sources/utils/utils.c \
		sources/utils/parse_numbers.c \
		sources/input_management/args_verifier.c \
		lib/get_next_line/get_next_line_utils.c \
		lib/get_next_line/get_next_line.c \

OBJS = $(SRCS:.c=.o)
NAME = push_swap
# Ensure libraries are built before linking
all: libft printf $(NAME)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(PRF) $(LIB)
# Ensure libraries are compiled
libft:
	make -C $(LIBFT_DIR) all
printf:
	make -C $(PRINTF_DIR) all
clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean
re: fclean all
test: all
	./fdf
	
leaks: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes ./fdf maps/test_maps/mars.fdf ./$(NAME)