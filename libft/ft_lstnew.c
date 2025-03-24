/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:20:31 by gdelhota          #+#    #+#             */
/*   Updated: 2025/02/14 16:07:23 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dll	*ft_lstnew(int content)
{
	t_dll	*res;

	res = (t_dll *) malloc(sizeof(t_dll));
	if (!res)
		return (NULL);
	res->content = content;
	res->next = res;
	res->prev = res;
	return (res);
}
