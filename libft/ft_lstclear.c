/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:17:27 by gdelhota          #+#    #+#             */
/*   Updated: 2024/12/28 20:56:10 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (*lst)
	{
		lst->previous->next = NULL;
		if ((*lst)->next)
			ft_lstclear(&((*lst)->next), (*del));
		ft_lstdelone(*lst, (*del));
		*lst = NULL;
	}
}
