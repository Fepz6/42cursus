/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 03:13:52 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/03/16 01:28:51 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print(int um, int tres)
{
	char	v[6];

	v[0] = (um / 10) + '0';
	v[1] = (um % 10) + '0';
	v[2] = ' ';
	v[3] = (tres / 10) + '0';
	v[4] = (tres % 10) + '0';
	write(1, v, 5);
	if (um != 98 || tres != 99)
	{
		write(1, ",", 1);
		write(1, " ", 1);
	}
}

void	ft_print_comb2(void)
{
	int	um;
	int	tres;

	um = 0;
	tres = 0;
	while (um <= 99)
	{
		tres = um + 1;
		while (tres <= 99)
		{
			print(um, tres);
		tres++;
		}
		tres = 0;
		um++;
	}
}
/*int main()
{
	ft_print_comb2();
}*/
