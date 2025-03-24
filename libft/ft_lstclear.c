/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:17:27 by gdelhota          #+#    #+#             */
/*   Updated: 2025/02/14 16:05:17 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_dll *lst)
{
	if (lst)
	{
		if (lst->prev)
			lst->prev->next = NULL;
		lst->prev = NULL;
		if (lst->next)
			ft_lstclear(lst->next);
		ft_lstdelone(lst);
		lst = NULL;
	}
}
