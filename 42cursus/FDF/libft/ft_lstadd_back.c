/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <fcosta-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:37:01 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/05/25 10:41:56 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list  *tmp;

    if (lst)
    {
        if(*lst == NULL)
            *lst = new;
        else
        {
            tmp = ft_lstlast(*(lst));
            tmp -> next = new;
        }
    }
}