/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <fcosta-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:07:29 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/08/01 15:55:35 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void    ft_bzero(void *s,size_t n)
{
    size_t  i;
    
    i = 0;
    while (i < n)
    {
        *((unsigned char *)s + i) = '\0';
        i++;
    }
}

size_t  ft_strlen(const char *s)
{
    size_t  i;

    i = 0;
    if (s == NULL)
        return(0);
    while(s[i] != '\0')
        i++;
    return (i);
}

char    *ft_strchr(const char *s, int c)
{
    if (s == NULL)
        return (NULL);
    while (*s != '\0')
    {
        if (*s == c)
            return ((char *)s);
            s++;
    }
    if (*s == '\0' && c == '\0')
        return ((char *)s);
    return (NULL);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *str;
    size_t  len;
    size_t  i;

    i = 0;
    len = ft_strlen(s1) + ft_strlen(s) + 1;
    str = (char * )malloc(len * sizeof(char));
    if (!str)
        return (NULL);
    while (s1 && *s1)
    {
        str[i++] = *s1;
        s1++;
    }
    while (s2 && s2*)
    {
        str[i++] = *s2;
        s2++;
    }
    str[i] = '\0';
    return (str);
}