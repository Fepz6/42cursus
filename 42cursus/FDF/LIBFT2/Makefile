# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcosta-e <fcosta-e@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/22 15:18:54 by fcosta-e          #+#    #+#              #
#    Updated: 2023/05/27 13:40:13 by fcosta-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf 
NAME = libft.a
SRCS = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memcpy.c\
ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strrchr.c ft_tolower.c ft_toupper.c\
ft_memchr.c ft_memcmp.c ft_strnstr.c ft_strdup.c ft_calloc.c ft_substr.c ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c\
ft_putchar_fd.c ft_striteri.c ft_strmapi.c ft_strtrim.c ft_split.c ft_strjoin.c ft_itoa.c
BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstmap.c ft_lstiter.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus: $(OBJS) $(BONUS_OBJS)
	$(AR) $(NAME) $(BONUS_OBJS) $(OBJS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)
	
fclean: clean
	$(RM) $(NAME)
	
re: fclean all

teste: re
	$(CC) main.c $(NAME) -o teste
