/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <fcosta-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:46:25 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/04/22 17:18:16 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  ft_strlcpy(char *dest, const char *src, size_t size)
{
  size_t i;
 
  i = 0;
  if (!size)
    return (strlen(src));
  while (src[i] && (i < size - 1))
  {
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0';
  return (strlen(src));
}
/*
int main() {
    char source[] = "Hello, world!";
    char destination[5];

    size_t len = ft_strlcpy(destination, source, sizeof(destination));

    printf("Copied %zu characters.\n", len);
    printf("Source: %s\n", source);
    printf("Destination: %s\n", destination);

    return 0;
}*/
