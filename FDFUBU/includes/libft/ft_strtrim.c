/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felipesilva <felipesilva@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 00:39:19 by fcosta-e          #+#    #+#             */
/*   Updated: 2024/04/16 03:34:47 by felipesilva      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	char	*new;

	start = 0;
	end = ft_strlen(s);
	while (ft_iswhitespace(s[start]))
		start++;
	while (ft_iswhitespace(s[end - 1]))
		end--;
	if (end < start)
		end = start;
	new = ft_strnew(end - start);
	if (new == NULL)
		return (NULL);
	return (ft_strncpy(new, s + start, end - start));
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