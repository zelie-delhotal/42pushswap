/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 21:42:59 by gdelhota          #+#    #+#             */
/*   Updated: 2024/12/28 21:51:42 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lststack(t_list *node,  t_list **stack)
{
	node->previous = *stack->previous;
	*stack->previous = *node;
	node->previous->next = node;
	node->next = *stack;
	*stack = node;
}
