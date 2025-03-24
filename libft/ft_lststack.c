/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 21:42:59 by gdelhota          #+#    #+#             */
/*   Updated: 2025/02/05 17:45:24 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lststack(t_list *node,  t_list *stack)
{
	if (node == NULL)
		return (0);
	if (stack != NULL)
	{
		node->prev = stack->prev;
		stack->prev = node;
		node->prev->next = node;
		node->next = stack;
	}
	*stack = *node;
	return (1);
}
