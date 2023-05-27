/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <fcosta-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:59:43 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/05/02 10:11:38 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strnstr(const char *big, const char *little, size_t len)
{
    size_t  i;

    if (*little == 0)
        return ((char *)big);
    if (len == 0)
        return (0);
    i = ft_strlen(little);
        while (*big && i <= len)
        {
            if (*big == *little && ft_strncmp(big, little, i) == 0)
            {
                return ((char *)big);
            }
            ++big;
            --len;
        }
    return (NULL);
}