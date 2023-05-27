/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <fcosta-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:06:09 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/05/25 11:17:43 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list *aux;

    if (!lst || !del)
        return ;
    while (*lst)
    {
        aux = (*lst) -> next;
        ft_lstdelone(*lst, del);
        (*lst) = aux;
    }
}