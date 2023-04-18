/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:19:59 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/03/30 01:02:00 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	str_cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

int	ft_print_params(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			write (1, &argv[i][j], 1);
			j++;
		}
		argv[i][j] = '\0';
		write (1, "\n", 1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	*max;
	int	j;

	i = 0;
	j = 1;
	if (argc > 0)
	{
		while (j < argc)
		{
			while (argv[j][i] != '\0')
			{
				len = str_len(argv[j]);
				if (argv[j][i] > argv[j][len])
				{
					res = argv[j][i];
					argv[j][i] = argv[j][len];
					argv[j][len] = argv[j][i];
				}
				write (1, &argv[j][i], 1);
				i++;
			}
			write (1, "\n", 1);
			j++;
			i = 0;
		}
	}
}
