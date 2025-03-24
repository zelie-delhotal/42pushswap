/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dll_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:15:52 by gdelhota          #+#    #+#             */
/*   Updated: 2025/03/20 19:58:53 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_dll_size(t_dll *lst)
{
	t_dll	*head;
	int		size;

	if (!lst)
		return (0);
	head = lst;
	size = 1;
	while (lst->next != head)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
