/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:56:03 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/03/21 21:13:20 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	a;

	a = 0;
	i = 1;
	while (str[a] != '\0')
	{
		if ((str[a] < 'a' || str[a] > 'z') || (str[a] < 'A' || str[a] > 'Z'))
		{
			if (str[i] >= 'a' || str[i] <= 'z')
			{
				str[i] = str[i] - 32;
				i++;
				a++;
			}
			i++;
			a++;
		}
	}
	return (str);
}
/*int	main()
{
	char	a[] = "42palavras quarenta-e-duas";
	ft_strcapitalize(a);
}*/
