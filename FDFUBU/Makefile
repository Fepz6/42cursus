.ONESHELL:
.SILENT:

NAME = fdf

SRCS_DIR = srcs/
OBJS_DIR = srcs/objs/
LIBFT_DIR = includes/libft/
MLX_DIR = includes/minilibx/
COMMIT_MESSAGE = "auto commit"

SRCS_LIST = fdf.c

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LIST))
OBJS = $(addprefix $(OBJS_DIR), $(SRCS_LIST:.c=.o))
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

MLX = $(addprefix $(MLX_DIR), libmlx.a)

CC = cc
RM = rm -rf
CFLAGS = -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lX11 -lXext -lm -o $(NAME)
	@echo "\033[1;36m[ ✔ ] creating $(NAME)...\033[0m"
	@echo "\033[1;32m[ ✔ ] $(NAME) ready!\033[0m"
	@echo "\033[1;3;5;33m 	- Let the journey begin! 🚀🗺️	\nUnleash the map's secrets with: ./fdf <map_file>\n\033[0m"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir $(OBJS_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR) > /dev/null 2>&1
	@echo "\033[1;35m[ ✔ ] preparing libft...\033[0m"


$(MLX):
	@make -C $(MLX_DIR) > /dev/null 2>&1
	@echo "\033[1;36m[ ✔ ] preparing minilibx...\033[0m"
	

clean:
	$(RM) $(OBJS_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)

re: fclean all
