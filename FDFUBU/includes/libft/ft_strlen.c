/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <fcosta-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:17:29 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/04/22 16:37:48 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlen(const char *s)
{
    size_t i;
    
    i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}
/*
int main()
{
    char a[] = "asqd";
    printf("%ld\n", ft_strlen(a));
}*/