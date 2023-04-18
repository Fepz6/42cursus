/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 23:30:36 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/03/29 01:54:54 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	int	result;

	result = 1;
	if (power == 0 && nb == 0)
		return (1);
	if (power < 0)
		return (0);
	else if (power > 0)
	{
		result = nb * ft_recursive_power(nb, power - 1);
	}
	return (result);
}
/*int	main()
{
	printf("%d", ft_recursive_power(2,3));
}*/
