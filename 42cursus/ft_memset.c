/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <fcosta-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:35:36 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/04/17 18:49:10 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memset(void *s, int c, size_t n)
{
    size_t  i;
    unsigned char *ar;

    i = 0;
    ar = (unsigned char*)s;
    while (i < n)
    {
        ar[i++] = (unsigned char)c;
    }
    return (s);
}
int main()
{
  printf("%s\n", "ft_memset");
    char   f[] = "kk";
	printf("%p\n", ft_memset(f, '$', 2));
    printf("%s\n", "----------------");
}