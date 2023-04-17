/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:12:10 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/04/12 18:14:05 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c += 32);
	return (c);
}

#include <stdio.h>
#include <ctype.h>
int main()
{
    char c, result;

    c = 'M';
    result = ft_tolower(c);
    printf("tolower(%c) = %c\n", c, result);

    c = 'm';
    result = ft_tolower(c);
    printf("tolower(%c) = %c\n", c, result);

    c = '+';
    result = ft_tolower(c);
    printf("tolower(%c) = %c\n", c, result);

    return 0;
}
