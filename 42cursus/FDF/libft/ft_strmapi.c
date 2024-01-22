/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <fcosta-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 00:27:43 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/05/16 00:38:37 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char    *aux;
    unsigned int    i;

    i = 0;
    aux = malloc(sizeof(char) * (ft_strlen(s) + 1));
    if (!aux)
        return (NULL);
    if (!s || !f)
        return (NULL);
    while (s[i] != '\0')
    {
        aux[i] = (*f)(i, s[i]);
        i++;
    }
    aux[i] = '\0';
    return (aux);
}