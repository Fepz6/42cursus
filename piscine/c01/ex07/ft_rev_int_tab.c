/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 00:17:20 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/03/18 15:12:15 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	count;
	int	i;
	int	num;

	count = 0;
	i = size - 1;
	while (count < size)
	{
		num = tab[i];
		i--;
		count++;
	}
}
/*int	main()
{
	int	intput[] = {2,4};
	int	size;

	size = 2;
	ft_rev_int_tab(intput ,size);
}*/
