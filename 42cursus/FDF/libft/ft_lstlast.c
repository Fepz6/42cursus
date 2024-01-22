/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <fcosta-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:24:27 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/05/25 10:35:50 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "libft.h"

t_list *ft_lstlast(t_list *lst)
{
    while (lst)
    {
        if (!lst -> next)
            return (lst);
        lst = lst -> next;
    }
    return (lst);
}