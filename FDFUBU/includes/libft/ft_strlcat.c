/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <fcosta-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:06:10 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/04/26 22:15:37 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t  i;
    size_t  j;

    i = 0;
    j = 0;
    while (dst[i] != '\0' && i < size)
    {
        i++;
    }
    if (i == size)
    {
        return (i + strlen(src));
    }
    while (src[j] != '\0' && (i + j < size - 1))
    {
        dst[i + j] = src[j];
        j++;
    }
    dst[i + j] = '\0';
    return (i + strlen(src));
}
/*int main()
{
    char str1[20] = "Hello";
    char str2[] = " world!";
    size_t result = ft_strlcat(str1, str2, sizeof(str1));

    printf("A string resultante é: %s\n", str1);
    printf("O comprimento total da string resultante é: %zu\n", result);

    return 0;
}*/