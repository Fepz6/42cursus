/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <fcosta-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:52:00 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/05/23 15:49:29 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strchr(const char *s, int c)
{
    char    aux;
    int i;

    i = 0;
    aux = (char)c;
    while (s[i] != '\0' && s[i] != aux)
        i++;
    if (s[i] == aux)
    {
        return (&((char *)s)[i]);
    }
    return (NULL);
}
/*
char* strchr(const char* str, int c);

int main() {
    char str[] = "hello, World";
    char* result;
    char* resultm;

    result = strchr(str, 'o');
    resultm = ft_strchr(str, 'o');
    printf("Primeira ocorrencia de 'o': %s\n", result);
    printf("Primeira ocorrencia de 'o': %s\n", resultm);

    result = strchr(str, 'z');
    printf("Primeira ocorrencia de 'z': %s\n", result);
    resultm = ft_strchr(str, 'z');
    printf("Primeira ocorrencia de 'z': %s\n", resultm);

    result = strchr(str, '\0');
    printf("Final da string: %s\n", result);
    resultm = ft_strchr(str, '\0');
    printf("Final da string: %s\n", resultm);

    return 0;
}*/