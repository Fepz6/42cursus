/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_repeat_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <fcosta-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:30:48 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/03/23 21:39:22 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
int count(char c)
{
    int result;

    result = 1;
    if (c >= 'a' && c <= 'z')
        result = c - 'a' + 1;
    else if (c >= 'A' && c <= 'Z')
        result = c - 'A' + 1;
    return (result);
}

int main (int ac, char **av)
{
    int i;
    int repeat;

i = 0;
    if (ac == 2)
    {
    	while (av[1][i] != '\0')
    	{
	    repeat = count(av[1][i]);
	    while ( repeat != 0)
	    {
		write (1, &av[1][i], 1);
		repeat--;
	    }
	    i++;
    	}
    }
    else
    {
	    return (write(1, "\n", 1));
    }
    write (1, "\n", 1);
}
