/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <fcosta-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:07:18 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/09/19 12:01:59 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putchar(int c)
{
    return write(1, &c, 1);
}

int ft_putstr(char *str)
{
    int contador = 0;

    if (!str)
    {
        write(1, "(null)", 6);
        return (6);
        
    }
    while (str[contador])
    {
        ft_putchar (str[contador]);
        contador++;
    }
    return contador;
}

int	ft_point_len(unsigned long nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		i++;
		nbr /= 16;
	}
	return (i);
}

void	ft_hex_to_str(unsigned long nbr)
{
	if (nbr >= 16)
	{
		ft_hex_to_str (nbr / 16);
		ft_hex_to_str (nbr % 16);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar(nbr + '0');
		else
			ft_putchar(nbr - 10 + 'a');
	}
}

int ft_putptr(unsigned long ptr)
{
	unsigned int	len;

	len = 0;
	if (ptr == 0)
		len = ft_putstr("(nil)");
	else
	{
		len = ft_putstr("0x");
		ft_hex_to_str(ptr);
		len += ft_point_len(ptr);
	}
	return (len);
}

int ft_putnbr(int n)
{
    int contador = 0;

    if (n == -2147483648)
    {
        write(1, "-2147483648", 11);
        contador += 11;
    }
    else
    {
        if (n < 0)
        {
            write(1, "-", 1);
            n = n * -1;
            contador++;
        }

        if (n >= 10)
        {
            contador += ft_putnbr(n / 10);
            contador += ft_putnbr(n % 10);
        }

        if (n < 10)
        {
            n = n + '0';
            contador += write(1, &n, 1);
        }
    }

    return contador;
}

int ft_putunbr(unsigned int n)
{
    int contador = 0;

    if (n >= 10)
    {
        contador += ft_putunbr(n / 10);
        contador += ft_putunbr(n % 10);
    }
    else
    {
        n = n + '0';
        contador += write(1, &n, 1);
    }

    return contador;
}


int ft_hexlen(unsigned int num)
{
    int length;

    length = 0;

    while (num != 0)
    {
        num = num / 16;
        length++;
    }

    return length;
}

void ft_printhex(unsigned int num, const char format)
{
    if (num >= 16)
    {
        ft_printhex(num / 16, format);
        ft_printhex(num % 16, format);
    }
    else
    {
        if (num <= 9)
            ft_putchar((num + '0'));
        else
        {
            if (format == 'x')
                ft_putchar((num - 10 + 'a'));
            if (format == 'X')
                ft_putchar((num - 10 + 'A'));
        }
    }
}

int ft_puthexadecimal(unsigned int num, const char type)
{
    if (num == 0)
        return (write(1, "0", 1));
    else
        ft_printhex(num, type);

    return (ft_hexlen(num));
}