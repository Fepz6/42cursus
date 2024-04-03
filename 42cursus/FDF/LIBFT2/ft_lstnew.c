/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-e <fcosta-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:13:41 by fcosta-e          #+#    #+#             */
/*   Updated: 2023/05/24 11:20:27 by fcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstnew(void *content)
{
    t_list  *new;
    
    new = malloc(sizeof(t_list));
    if (new == NULL)
        return (0);
    new -> content = content;
    new -> next = NULL;
    return (new);
}