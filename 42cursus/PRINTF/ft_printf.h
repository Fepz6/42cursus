/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <fcosta-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:43:50 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/09/18 16:51:49 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>

int ft_printf(const char *fmt, ...);
int ft_putchar(int c);
int ft_putstr(char *str);
int ft_putptr(void *ptr);
int ft_putnbr(int n);
int ft_putunbr(unsigned int n);
int ft_hexlen(unsigned int num);
void ft_printhex(unsigned int num, const char format);
int ft_puthexadecimal(unsigned int num, const char type);

#endif