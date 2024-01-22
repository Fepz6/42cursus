/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <fcosta-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:06:10 by fcosta-e          #+#    #+#             */
/*   Updated: 2024/01/22 12:03:20 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (size <= ft_strlen(dest))
		return (size + ft_strlen(src));
	i = ft_strlen(dest);
	j = 0;
	while (src[j] != 0 && (i + 1) < size)
		dest[i++] = src[j++];
	dest[i] = 0;
	return (i + ft_strlen(&src[j]));
}
/*int main()
{
    char str1[20] = "Hello";
    char str2[] = " world!";
    size_t result = ft_strlcat(str1, str2, sizeof(str1));

    printf("A string resultante é: %s\n", str1);
    printf("O comprimento total da string resultante é: %zu\n", result);

    return 0;
}*/
