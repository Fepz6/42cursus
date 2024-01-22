/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <fcosta-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:57:11 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/04/22 16:37:10 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char   *d;
    const unsigned char *s;
    
    s = src;
    d = dest;
    if (!dest && !src)
        return (dest);
    while (n > 0)
    {
        *d = *s;
        d++;
        s++;
        n--;
    }
    return (dest);
}
/*
int main() {
    int array1[] = {1, 2, 3, 4, 5};
    int array2[5];

    // Copia o conteúdo do array1 para o array2 usando memcpy
    ft_memcpy(array2, array1, sizeof(array1));

    // Imprime os valores do array2
    for (int i = 0; i < 5; i++) {
        printf("%d ", array2[i]);
    }
    printf("\n");

    return 0;
}*/