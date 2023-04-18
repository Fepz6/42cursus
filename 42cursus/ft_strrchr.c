/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <fcosta-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:34:34 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/04/18 20:16:54 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
    int i;

    i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    while (i >= 0)
    {
        if (s[i] == (char)c)
            return (((char *)s)+i);
        i--;
    }
    if (c == '\0')
        return (((char *)s)+i);
    return NULL;
    
}

int main() {
    char str[] = "hello, World";
    char* result;
    char* resultm;

    result = strrchr(str, 'o');
    resultm = ft_strrchr(str, 'o');
    printf("Primeira ocorrencia de 'o': %s\n", result);
    printf("Primeira ocorrencia de 'o': %s\n", resultm);

    result = strrchr(str, 'z');
    printf("Primeira ocorrencia de 'z': %s\n", result);
    resultm = ft_strrchr(str, 'z');
    printf("Primeira ocorrencia de 'z': %s\n", resultm);

    result = strrchr(str, '\0');
    printf("Final da string: %s\n", result);
    resultm = ft_strrchr(str, '\0');
    printf("Final da string: %s\n", resultm);

    return 0;
}