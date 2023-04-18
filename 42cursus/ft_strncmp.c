/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <fcosta-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 20:19:35 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/04/18 21:01:08 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] == s2[i])
		{
			i++;
		}
		else
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
	}
	return (0);
}
int main() {
    char str1[] = "Hello, world!";
    char str2[] = "Hell";
    int n = 8;
    int result = strncmp(str1, str2, n);
    int resultm = ft_strncmp(str1, str2, n);
    
    if (result == 0) {
        printf("As primeiras %d letras de \"%s\" e \"%s\" sao iguais.\n", n, str1, str2);
    } else if (result < 0) {
        printf("As primeiras %d letras de \"%s\" sao menores que as de \"%s\".\n", n, str1, str2);
    } else {
        printf("As primeiras %d letras de \"%s\" sao maiores que as de \"%s\".\n", n, str1, str2);
    }
    
     if (resultm == 0) {
        printf("As primeiras %d letras de \"%s\" e \"%s\" sao iguais.\n", n, str1, str2);
    } else if (resultm < 0) {
        printf("As primeiras %d letras de \"%s\" sao menores que as de \"%s\".\n", n, str1, str2);
    } else {
        printf("As primeiras %d letras de \"%s\" sao maiores que as de \"%s\".\n", n, str1, str2);
    }
    return 0;
}