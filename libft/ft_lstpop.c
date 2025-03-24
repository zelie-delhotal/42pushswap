/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 21:06:09 by gdelhota          #+#    #+#             */
/*   Updated: 2025/03/20 20:44:05 by gdelhota         ###   ########.fr       */
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
		node = *lst;
		node->prev->next = node->next;
		node->next->prev = node->prev;
		if (node->next != node)
			*lst = node->next;
		else
			*lst = NULL;
		node->next = node;
		node->prev = node;
		return (node);
	}
	return (NULL);
}
/*
#include "../push_swap.h"
int main(int ac, char **av)
{
	t_dll *lst = ft_dll_builder(ac, av);
	put_list("initiale", lst);
	t_dll *node = ft_lstpop(&lst);
	put_list("node", node);
	put_list("list", lst);
	ft_lstpush(&node, &lst);
	put_list("node", node);
	put_list("list", lst);
	ft_lstpush(&lst, &node);
	put_list("node", node);
	put_list("list", lst);
	ft_lstpush(&lst, &node);
	put_list("node", node);
	put_list("list", lst);
	ft_lstpush(&lst, &node);
	put_list("node", node);
	put_list("list", lst);
	ft_lstpush(&lst, &node);
	put_list("node", node);
	put_list("list", lst);
}*/
