/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <fcosta-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 22:24:26 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/05/23 15:37:42 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
    unsigned char *p;

    p = (unsigned char *)s;
    c = (unsigned char)c;
    while (n && *p != c)
    {
        ++p;
        --n;
    }
    if (n)
            return ((void*)p);
    else
        return (NULL);
}