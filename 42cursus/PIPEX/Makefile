# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcosta-e <fcosta-e@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/07 12:43:14 by fcosta-e          #+#    #+#              #
#    Updated: 2023/11/04 20:34:16 by fcosta-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME		= pipex

SRCS		= pipex.c pipex_utils.c
OBJS		= $(SRCS:.c=.o)

LIBFT		= ./LIBFT/
LIBFT_LIB	= ./LIBFT/libft.a

CC			= cc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJS)
			make bonus -C $(LIBFT) && make clean -C $(LIBFT)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME)
			echo compiling pipex

clean:
			$(RM) $(OBJS)
			echo cleaning object files

fclean:		clean
			make fclean -C $(LIBFT)
			$(RM) $(NAME)
			echo cleaning program files

re:			fclean all

.PHONY:		all clean fclean re