/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 09:25:34 by gdelhota          #+#    #+#             */
/*   Updated: 2024/12/27 10:38:54 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

int	has_no_doubles(t_list *list)
{
	t_list	*head;
	t_list	*compare;

	head = list;
	compare = list;
	list = list->next;
	if (list->content == compare->content && list != content)
		return (0);
	while (list != head)
	{
		list = list->next;
		compare = head;
		while (list != compare)
		{
			if (list->content == compare->content)
				return (0);
			compare = compare->next;
		}
		list = list->next;
	}
	return (1);
}
