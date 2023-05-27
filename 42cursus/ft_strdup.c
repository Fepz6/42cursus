/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <fcosta-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:27:47 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/05/06 00:33:23 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strdup(const char *s)
{
    char    *d;
    size_t  n;
    
    n = ft_strlen(s) + 1;
    d = malloc(n);
    if (d == NULL)
        return (NULL);
    else
        ft_memcpy(d, s, n);
    return (d);
}