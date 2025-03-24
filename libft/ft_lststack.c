/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 21:42:59 by gdelhota          #+#    #+#             */
/*   Updated: 2025/03/18 16:32:32 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dll	*ft_lststack(t_dll *node, t_dll *stack)
{
	if (node == NULL)
	{
		ft_lstclear(stack);
		return (NULL);
	}
	if (stack != NULL)
	{
		node->prev = stack->prev;
		stack->prev = node;
		node->prev->next = node;
		node->next = stack;
	}
	else
	{
		node->prev = node;
		node->next = node;
	}
	return (node);
}
