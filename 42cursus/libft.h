/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <fcosta-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:22:38 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/04/22 17:11:52 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

size_t ft_strlen(const char *s);
size_t  ft_strlcpy(char *dest, const char *src, size_t size);
size_t ft_strlen(const char *s);

int ft_atoi(const char *nptr);
int	ft_isalnum(int a);
int	ft_isalpha(int c);
int	ft_isascii(int a);
int	ft_isdigit(int i);
int	ft_isprint(int a);
int ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_tolower(int c);
int	ft_toupper(int c);

void ft_bzero(void *s, size_t n);
void *ft_memcpy(void *dest, const void *src, size_t n);
void *ft_memmove(void *dest, const void *src, size_t n);
void *ft_memset(void *s, int c, size_t n);

char    *ft_strchr(const char *s, int c);
char *ft_strrchr(const char *s, int c);


#endif