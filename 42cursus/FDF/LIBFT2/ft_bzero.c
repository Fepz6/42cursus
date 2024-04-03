/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <fcosta-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:11:46 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/04/22 18:01:02 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_bzero(void *s, size_t n)
{
    unsigned char   *p;
    
    p = s;
    while (n)
    {
        *p++ = 0;
        --n;
    }
       
}

/*void printArray(int arr[], int size){
    printf("[ ");
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("]\n");
}
   int arr[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {1, 2, 3, 4, 2};

    printf("Array antes de bzero:\n");
    printArray(arr, 5);
    
    bzero(arr, sizeof(arr));
    printf("Array antes de bzero:\n");
    printArray(arr2, 5);
    ft_bzero(arr2, sizeof(arr2));

    printf("Array depois de bzero:\n");
    printArray(arr, 5);
    printf("Array depois de bzero:\n");
    printArray(arr2, 5);
    printf("bzero --------");*/
    