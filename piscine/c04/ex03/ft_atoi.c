/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 22:52:13 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/03/27 01:20:18 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	result = 0;
	sign = 0;
	while ((str[i] != '\0') && (str[i] < '0' || str[i] > '9'))
	{
		if (str[i] == '-')
			sign++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + str[i] - '0';
		i++;
	}
	if (sign % 2 == 1)
		return (result * -1);
	return (result);
}
/*int	main()
{
	char	a[] = " ---+---++422ab567";
	printf("%d",ft_atoi(a));
	return (0);
}*/
