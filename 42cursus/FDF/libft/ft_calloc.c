/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <fcosta-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 22:40:47 by fcosta-e          #+#    #+#             */
/*   Updated: 2024/01/22 11:58:38 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*Allocates the requested memory and returns a 
pointer to it. Calloc, unlike Malloc, 
sets the allocated memory to zero.*/
#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	char	*memory;
	size_t	i;

	i = 0;
	memory = malloc(nitems * size);
	if (memory == NULL)
		return (0);
	while (i < nitems * size)
	{
		memory[i] = 0;
		i++;
	}
	return (memory);
}
