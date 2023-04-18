/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 23:12:28 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/03/16 00:15:13 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	pos;
	char	v[12];

	if (nb != 0)
	{
		if (nb < 0)
		{
			nb = -nb;
			write(1, "-", 1);
		}
		while (nb > 0)
		{
			v[pos] = (nb % 10) + '0';
			nb = nb / 10;
			pos++;
		}
		while (pos >= 0)
		{
			write(1, &v[pos], 1);
			pos--;
		}
	}
	else
		write(1, "0", 1);
}
/*int main()
{
	ft_putnbr(0);
}*/
