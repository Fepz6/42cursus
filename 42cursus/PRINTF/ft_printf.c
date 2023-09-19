/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <fcosta-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:43:34 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/09/18 15:48:45 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *fmt, ...)
{
    size_t i;
    int contador = 0;
    va_list ptr;

    i = 0;
    va_start(ptr, fmt);

    while (fmt[i])
    {
        if (fmt[i] == '%')
        {
            i++;
            if (fmt[i] == 'c')
            {
                contador += ft_putchar(va_arg(ptr, int));
            }
            else if (fmt[i] == 's')
            {
                char *str = va_arg(ptr, char *);
                contador += ft_putstr(str);
            }
            else if (fmt[i] == 'p')
            {
                void *ptr_arg = va_arg(ptr, void *);
                contador += ft_putptr(ptr_arg);
            }
            else if (fmt[i] == 'd' || fmt[i] == 'i')
            {
                int num = va_arg(ptr, int);
                contador += ft_putnbr(num);
            }
            else if (fmt[i] == 'x' || fmt[i] == 'X')
            {
                int hex = va_arg(ptr, unsigned int);
                contador += ft_puthexadecimal(hex, fmt[i]);
            }
            else if (fmt[i] == 'u')
            {
                unsigned int num = va_arg(ptr, unsigned int);
                contador += ft_putunbr(num);
            }
            else if (fmt[i] == '%')
            {
                contador += ft_putchar('%');
            }
        }
        else
        {
            contador += ft_putchar(fmt[i]);
        }
        i++;
    }

    va_end(ptr);
    return contador;
}

/*int main()
{
    ft_printf("olaaa odkwo");
    //printf("olaaa odkwo %c %s %p %d %x %u\n", '2', "3e1e2edskt", (void *)12345, -26, 10111214, 429584995);
    return 0;
}*/