/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 02:00:23 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/03/29 21:06:16 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <limits.h>

int	ft_fibonacci(int index)
{
	int	i;

	if (index == 0)
		return (0);
	else if (index == 1)
		return (1);
	else if (index > 1)
	{
		i = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
		return (i);
	}
	else
	{
		return (-1);
	}
}
int	main()
{	
	printf("%d", INT_MIN);
	printf("%d", ft_fibonacci(7));
}
