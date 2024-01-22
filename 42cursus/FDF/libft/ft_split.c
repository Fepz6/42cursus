/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <fcosta-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:31:25 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/05/23 15:09:09 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "libft.h"

static int  countw(const char *s, char c)
{
    int i;
    int cWords;

    i = 0;
    cWords = 0;
    while (s[i])
    {
        if (s[i] != c)
        {
            cWords++;
            while (s[i] && s[i] != c)
            {
                i++;
            }
        }
        else
        {
            i++;
        }
    }
    return (cWords);
}

static char *alocW (const char *str, char c)
{
    int i;
    char    *p;
    
    i = 0;
    while (str[i] && str[i] != c)
        i++;
    p = malloc(sizeof(char) * (i + 1));
    if (!p)
        return (NULL);
    i = 0;
    while (str[i] && str[i] != c)
    {
        p[i] = str[i];
        i++;
    }
    p[i] = '\0';
    return (p);
}

char **ft_split(char const *s, char c)
{
    int i;
    int j;
    char **w;

    i = 0;
    j = 0;
    w = malloc(sizeof(char *) * (countw(s, c) + 1));
    if (!w)
        return (NULL);
    while (s[i])
    {
        if(s[i] != c)
        {
            w[j] = alocW(&s[i], c);
            while (s[i] && s[i] != c)
                i++;
            j++;
        }
        else
            i++;
    }
    w[j] = 0;
    return (w);
}