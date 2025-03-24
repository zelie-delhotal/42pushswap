/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 21:06:09 by gdelhota          #+#    #+#             */
/*   Updated: 2025/03/18 16:32:43 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// pops the first element of a dll and returns it
// head of the list becomes the next element or NULL if empty
t_dll	*ft_lstpop(t_dll **lst)
{
	t_dll	*node;

	if (*lst)
	{
		if ((*lst)->prev)
			(*lst)->prev->next = (*lst)->next;
		if ((*lst)->next)
			(*lst)->next->prev = (*lst)->prev;
		node = *lst;
		if ((*lst)->next != (*lst))
			*lst = (*lst)->next;
		else
			*lst = NULL;
		node->next = node;
		node->prev = node;
		return (node);
	}
	return (NULL);
}
