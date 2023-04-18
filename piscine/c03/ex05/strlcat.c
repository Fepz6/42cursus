/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 00:17:26 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/03/25 00:11:51 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	str_len(char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	h;

	i = 0;
	h = str_len(src);
	j = str_len(dest);
	if (size == 0 || size <= j)
		return (h + size);
	while (src[i] != '\0' && i < size - j - 1)
	{
		dest[j + i] = src[i];
		i++;
	}
	dest[j + i] = '\0';
	return (h + j);
}
int	main()
{
	char	new[8] = "42 te";
	char	old[] = " amo";
	ft_strlcat(new,old,3);
	printf("%d", ft_strlcat(new,old,15));
}
