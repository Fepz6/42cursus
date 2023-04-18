/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:09:55 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/03/29 21:04:30 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	int	result;

	result = nb;
	if (result == 0)
		return (1);
	if (nb < 0)
		return (0);
	else
	{
		result = result * ft_recursive_factorial(nb - 1);
	}
	return (result);
}
/*int	main ()
{
	printf("%d", ft_recursive_factorial(0));
}*/
