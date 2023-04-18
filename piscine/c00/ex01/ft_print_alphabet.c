/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 22:43:48 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/03/15 22:50:36 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{		
	char	alph;

	alph = 'a';
	while (alph <= 'z')
	{
		write(1, &alph, 1);
		alph++;
	}
}	
/*	int main()
 	{
		ft_print_alphabet();
		return(0);
	}*/
