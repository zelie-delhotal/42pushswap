/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 21:06:09 by gdelhota          #+#    #+#             */
/*   Updated: 2025/02/05 17:47:05 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// pops the first element of a dll and returns it
// head of the list becomes the next element or NULL if empty
t_list	*ft_lstpop(t_list *lst)
{
	t_list	*temp;
	if (lst)
	{
		if (lst->prev)
			lst->prev->next = lst->next;
		if (lst->next)
			lst->next->prev = lst->prev;
	}
	temp = lst;
	if (lst->next != lst)
		*lst = *(lst->next);
	else
		lst = NULL;
	temp->next = temp;
	temp->prev = temp;
	return (temp);
}
