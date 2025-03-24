/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted_dll.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:01:06 by gdelhota          #+#    #+#             */
/*   Updated: 2025/03/20 02:19:37 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_sorted_dll(t_dll *lst)
{
	t_dll	*head;

	if (lst == NULL || lst->next == lst)
		return (1);
	head = lst;
	lst = lst->next;
	while (lst != head)
	{
		if (lst->content < lst->prev->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}
