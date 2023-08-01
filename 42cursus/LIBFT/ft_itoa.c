/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <fcosta-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:10:09 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/05/24 11:08:32 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int  count(int n)
{
    int    size;

    size = 0;
    if (n <= 0)
        size++;
    while (n != 0)
    {
        n = n / 10;
        size++;
    }
    return (size);
}
static char faux(char *aux, long int size, int n, int i)
{
    aux[size] = '\0';
    while (i + 1 < size)
    {
        aux[size - 1] = n % 10 + '0';
        n = n / 10;
        size--;
    }
    return (*aux);
}

char *ft_itoa(int n)
{
    char    *aloc;
    int i;
    long int    size;

    i = -1;
    size = count(n);
    aloc = malloc(sizeof(char) * size + 1);
    if (!(aloc))
        return (NULL);
    if (n == -2147483648)
    {
        aloc[0] = '-';
        aloc[1] = '2';
        n = 147483648;
        i = 1;
    }
    else if (n < 0)
    {
        aloc[0] = '-';
        n = n * -1;
        i = 0;
    }
    faux(aloc, size, n, i);
    return (aloc);
}