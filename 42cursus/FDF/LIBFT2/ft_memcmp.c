/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <fcosta-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 22:54:57 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/04/28 12:54:37 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    const unsigned char *p;
    const unsigned char *r;

    p = (unsigned char *)s1;
    r = (unsigned char *)s2;
    while (n > 0 && *p == *r)
    {
        ++p;
        ++r;
        --n;
    }
    if (n)
        return (*p - *r);
    else
        return (0);
}
/*int main() {
    char str1[] = "Hello, world!";
    char str2[] = "Hello, world!";
    char str3[] = "Hello, everyone!";

    int result1 = ft_memcmp(str1, str2, sizeof(str1));
    int result2 = ft_memcmp(str1, str3, sizeof(str1));

    if (result1 == 0) {
        printf("As strings str1 e str2 sao iguais\n");
    } else {
        printf("As strings str1 e str2 sao diferentes\n");
    }

    if (result2 < 0) {
        printf("A string str1 eh menor do que a string str3\n");
    } else if (result2 > 0) {
        printf("A string str1 eh maior do que a string str3\n");
    } else {
        printf("As strings str1 e str3 sao iguais\n");
    }

    return 0;
}*/