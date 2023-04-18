/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:00:44 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/03/18 15:06:10 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	c;

	c = *a;
	*a = (*a / *b);
	*b = (c % *b);
}
/*int	main()
{
	int	one;
	int	two;

	one = 0;
	two = 0;
	ft_ultimate_div_mod(&one ,&two);
}*/
