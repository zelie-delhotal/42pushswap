/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted_dll.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:01:06 by gdelhota          #+#    #+#             */
/*   Updated: 2025/03/19 17:01:34 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_sorted_dll(t_dll *lst)
{
	t_dll	*head;
	int		comp_value;

	if (lst == NULL)
		return (1);
	comp_value = lst->content;
	head = lst;
	if (comp_value > lst->content)
		return (0);
	lst = lst->next;
	while (lst != head)
	{
		if (comp_value > lst->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

