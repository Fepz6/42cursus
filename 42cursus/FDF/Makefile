# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: felipesilva <felipesilva@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 21:26:58 by felipesilva       #+#    #+#              #
#    Updated: 2024/02/04 23:46:20 by felipesilva      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME = fdf

# src / obj files
SRC = fdf.c read.c
OBJ = $(SRC:.c=.o)

# CC
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# mlx
MLX = ./minilibx_macos/
MLX_LIB = $(addprefix $(MLX), mlx.a)
MLX_INC = -I ./minilibx_macos
MLX_LNK = -L ./minilibx_macos -lmlx -framework OpenGL -framework AppKit

# libft
LIBFT = ./libft/
LIBFT_LIB = $(addprefix $(LIBFT), libft.a)
LIBFT_INC = -I ./libft
LIBFT_LNK = -L ./libft -lft

all: $(NAME)

$(NAME): $(LIBFT_LIB) $(MLX_LIB) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT_LNK) $(MLX_LNK)

$(LIBFT_LIB):
	@make -C $(LIBFT)

$(MLX_LIB):
	@make -C $(MLX)

%.o: %.c
	$(CC) $(CFLAGS) $(LIBFT_INC) $(MLX_INC) -o $@ -c $<

clean:
	@make -C $(LIBFT) clean
	@make -C $(MLX) clean
	rm -f $(OBJ)

fclean: clean
	@make -C $(LIBFT) fclean
	rm -f $(NAME)

re: fclean all

leaks: $(NAME)
	leaks $(NAME)


