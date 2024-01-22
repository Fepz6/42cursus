/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <fcosta-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:46:25 by fcosta-e          #+#    #+#             */
/*   Updated: 2024/01/22 12:04:19 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;
	size_t	i;

	srcsize = ft_strlen(src);
	i = -1;
	if (dstsize != 0)
	{
		while (src[++i] && i < (dstsize - 1))
			dst[i] = src[i];
		dst[i] = '\0' ;
	}
	return (srcsize);
}
/*
int main() {
    char source[] = "Hello, world!";
    char destination[5];

    size_t len = ft_strlcpy(destination, source, sizeof(destination));

    printf("Copied %zu characters.\n", len);
    printf("Source: %s\n", source);
    printf("Destination: %s\n", destination);

    return 0;
}*/
