/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:00:46 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/04/12 17:21:26 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int i)
{
	if (i >= '0' && i <= '9')
		return (1);
	return (0);
}

#include <stdio.h>
#include <ctype.h>

int main()
{
    char c;
    c='5';
    printf("Result when numeric character is passed: %d", ft_isdigit(c));

    c='+';
    printf("\nResult when non-numeric character is passed: %d", ft_isdigit(c));

    return 0;
}
