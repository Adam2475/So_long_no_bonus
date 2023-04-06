# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adpassar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/30 18:49:01 by adpassar          #+#    #+#              #
#    Updated: 2023/04/04 17:27:31 by adpassar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -Iheaders/

LIBFT = libft/libft.a

PRINTF = ft_printf/ft_printf.h

LIB = minilibx/libmlx_Linux.a -lX11 -lXext -lm

MLX = minilibx/

FLAG = -lXext -lX11 -lm -lzs

SRC = src/main.c src/utils/map.c src/utils/ft_close.c src/utils/images.c src/utils/command.c src/utils/floodfill.c
OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	# @echo "⌛ compiling...⌛"
	$(MAKE) -s -C libft/
	$(MAKE) -s -C $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) $(LIBFT) -o $(NAME)
	# @echo "🎉 so_long compiled! 🎉"

clean:	
	@echo "🧽 cleaning... 🧽"
	@rm -f $(OBJ) $(OBJ_BONUS)
	@make clean -s -C libft/

fclean: clean
	@echo "🚮♻️ spring cleaning, rm $(NAME)... ♻️ 🚮" 
	make clean -C $(MLX)
	rm -rf $(NAME)

re: fclean all

.SILENT: