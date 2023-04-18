/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 23:02:34 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/03/15 23:19:14 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(int one, int two, int three)
{
	write(1, &one, 1);
	write(1, &two, 1);
	write(1, &three, 1);
	if (one != '7' || two != '8' || three != '9')
	{
		write(1, ",", 1);
	}
}

void	ft_print_comb(void)
{
	char	one;
	char	two;
	char	three;

	one = '0';
	two = '0';
	three = '0';
	while (one <= '9')
	{
		two = one + 1;
		while (two <= '9')
		{
			three = two + 1;
			while (three <= '9')
			{
				print(one, two, three);
			three++;
			}
		two++;
		}
	one++;
	}
}
/*int	main()
{
	ft_print_comb();
}*/
