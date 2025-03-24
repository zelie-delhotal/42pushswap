/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 21:42:59 by gdelhota          #+#    #+#             */
/*   Updated: 2025/03/20 00:53:44 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lststack(t_dll *node, t_dll **stack)
{
	if (node == NULL)
		ft_lstclear(*stack);
	if (*stack != NULL)
	{
		node->prev = (*stack)->prev;
		(*stack)->prev = node;
		node->prev->next = node;
		node->next = *stack;
	}
	else
	{
		node->prev = node;
		node->next = node;
	}
	*stack = node;
}
