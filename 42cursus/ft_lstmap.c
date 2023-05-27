/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <fcosta-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:44:38 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/05/27 13:36:58 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *new_lst;
    t_list  *new_cont;

    if (!lst)
        return(NULL);
    new_lst = 0;
    while (lst)
    {
        new_cont = ft_lstnew(f(lst -> content));
        while (!new_cont)
        {
            ft_lstclear(&new_lst, del);
            return (0);
        }
        ft_lstadd_back(&new_lst, new_cont);
        lst = lst -> next;
    }
    return (new_lst);
}