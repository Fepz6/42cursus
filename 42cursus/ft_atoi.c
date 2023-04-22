/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <fcosta-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:22:16 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/04/22 16:39:13 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_atoi(const char *nptr)
{
    int i;
    int a;
    int r;

    i = 0;
    a = 1;
    r = 0;
    while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
        i++;
    if (nptr[i] == '+' || nptr[i] == '-')
    {
        if (nptr[i] == '-')
            a *= -1;
        i++;
    }
    while (nptr[i] >= '0' && nptr[i] <= '9')
    {
        r = r * 10 + nptr[i] - '0';
        i++;
    }
    return (r * a);
}