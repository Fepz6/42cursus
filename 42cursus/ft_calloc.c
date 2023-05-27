/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <fcosta-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 22:40:47 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/05/23 15:35:38 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_calloc(size_t nmemb, size_t size)
{
    char    *m;
    size_t  i;
    
    i = 0;
    m = malloc(size * nmemb);
    
    if (m == NULL)
        return (0);
    while (i < nmemb * size)
    {
        m[i] = 0;
        i++;
    }
    return (m); 
}
