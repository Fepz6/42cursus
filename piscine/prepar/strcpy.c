/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 23:45:57 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/03/31 00:12:51 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	count_alpha( char c)
{
	int	i;

	i = 0;
	if (c >= 'a' && c <= 'z')
	{
		i = c - ('a' - 1);
	}
	else if (c >= 'A' && c <= 'Z')
	{
		i = c - ('A' - 1);
	}
	else
	{
		return (1);
	}
	return (i);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i] != '\0')
		{
			j = count_alpha(argv[1][i]);
			while (j > 0)
			{
				write (1, &argv[1][i], 1);
				j--;
			}
			i++;
		}
	}
	return (0);
}
