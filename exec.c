/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:34:57 by gdelhota          #+#    #+#             */
/*   Updated: 2025/03/19 20:08:38 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec(char *order, t_dll **lsta, t_dll **lstb)
{
	ft_printf("%s\n", order);
	if (str_equals(order, "ra"))
		*lsta = (*lsta)->next;
	if (str_equals(order, "rb"))
		*lstb = (*lstb)->next;
	if (str_equals(order, "rr"))
	{
		*lsta = (*lsta)->next;
		*lstb = (*lstb)->next;
	}
	if (str_equals(order, "rra"))
		*lsta = (*lsta)->prev;
	if (str_equals(order, "rrb"))
		*lstb = (*lstb)->prev;
	if (str_equals(order, "rrr"))
	{
		*lsta = (*lsta)->prev;
		*lstb = (*lstb)->prev;
	}
	if (str_equals(order, "pa"))
		*lsta = ft_lstpush(lstb, *lsta);
	if (str_equals(order, "pb"))
		*lstb = ft_lstpush(lsta, *lstb);
}
