/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felipesilva <felipesilva@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:36:30 by fcosta-e          #+#    #+#             */
/*   Updated: 2024/04/16 21:21:16 by felipesilva      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd(t_list **lst, t_list *new)
{
    if (lst && new)
    {
        new -> next = *lst;
        *lst = new;
    }
}