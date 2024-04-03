/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <fcosta-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:31:15 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/04/22 16:37:16 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void   *ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char   *d;
    const unsigned char *s;
    
    d = (unsigned char *)dest;
    s = (unsigned char *)src;
    if (!dest && !src)
        return (dest);
    if (d < s)
    {
        while (n--)
            *d++ = *s++;
        return (dest);
    }
    else
    {
        while (n--)
            d[n] = s[n];
    }
    return (dest);
}
/*
int main ()
{
  char str[20] = "hello, world";
  char str2[15] = "   ";
  printf("str %s\n", str);
  printf("str2 %s\n", str2);
  ft_memmove(str2, str, 5);
	
    printf("str %s\n", str);  
    printf("str2 %s\n", str2);
 return 0;
}*/