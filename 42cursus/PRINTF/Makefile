# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcosta-e <fcosta-e@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 14:46:41 by fcosta-e          #+#    #+#              #
#    Updated: 2023/09/12 15:06:41 by fcosta-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME =  libftprintf.a

SRCS = ft_printf.c ft_printf_func.c
OBJS = ${SRCS:.c=.o}

CC		= gcc
RM		= /bin/rm -f
CFLAGS	= -Wall -Wextra -Werror -I ${INC}

INC	= ./
CL = ar -rc
RL = ar -s

${NAME}:	${OBJS}
	${CL}	${NAME}	${OBJS}
	${RL}	${NAME}
	printf "Compiling the program..\033[0;32m [OK]\033[0m\n"

all: ${NAME}

clean:
	${RM} ${OBJS}
	printf "Removing object files..\033[0;32m [OK]\033[0m\n"

fclean:	clean
	${RM}	${NAME}
	printf "Removing executable....\033[0;32m [OK]\033[0m\n"

re: fclean all

norm:
	printf "\033[0;32mRunning Norminette\n\n\033[0m"
	printf "\033[0;35mInclude\n\033[0m"
	norminette -R CheckDefine *.h
	printf "\033[0;36m\nFunctions\n\033[0m"
	norminette -R CheckForbiddenSourceHeader *.c
	printf "\n"
	
.PHONY: clean fclean all re