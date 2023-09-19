/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <fcosta-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:07:18 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/09/18 17:29:59 by fcosta-e         ###   ########.fr       */
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

int ft_putptr(void *ptr)
{
    unsigned long num = (unsigned long)ptr;
    char *hex_digits = "0123456789abcdef";
    write(1, "0x", 2);

    
    int count = 0;
    char buffer[200];

    if (num == 0)
    
    {
        write(1, "(nil)", 5);
        return (5);
    }

    while (num != 0)
    {
        buffer[count] = hex_digits[num % 16];
        num /= 16;
        count++;
    }

    while (count > 0)
    {
        count--;
        ft_putchar(buffer[count]);
    }

    return count;
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