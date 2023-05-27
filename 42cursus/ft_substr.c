/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <fcosta-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:24:17 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/05/18 20:19:56 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    unsigned int    i;
    char    *p;
    size_t  slen;
    
    if (s == NULL)
        return (NULL);
    if (start >= ft_strlen(s))
        return (ft_strdup(""));
    if (len > ft_strlen(s) - start)
        len = ft_strlen(s) - start;
    i = start;
    slen = 0;
    p = malloc(sizeof(*s) * (len + 1));
    if (p == NULL)
        return (NULL);
    ft_strlcpy(p, s + start, len + 1);
    return (p);
}