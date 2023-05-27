/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <fcosta-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 00:39:19 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/05/18 20:11:37 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
    char    *trimmed;
    size_t i;
    size_t f;

    i = 0;
    f = ft_strlen(s1) - 1;
    if (s1 == NULL || set == NULL)
        return (NULL);
    while (s1[i] != '\0' && ft_strchr(set, s1[i]) != NULL)
        i++;
    while (f > i && strchr(set, s1[f]) != NULL)
        f--;
    trimmed = ft_substr(s1, i, f - i + 1);
    return (trimmed);
}   
    /*if (f < i)
    {
        char *strnull = malloc(1);
        strnull[0] = '\0';
        return (strnull);
    }
    size_t newstri;
    
    newstri = f - i + 1;
    char* newstr = malloc(newstri + 1);
    strncpy(newstr, s1 + i, newstri);
    return ( newstr);
}*/