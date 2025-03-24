/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dll_builder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:57:47 by gdelhota          #+#    #+#             */
/*   Updated: 2025/03/20 18:01:18 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dll	*ft_dll_builder(int ac, char **av)
{
	int		i;
	int		value;
	t_dll	*lst;

	if (ac < 2)
		return (NULL);
	lst = NULL;
	i = 0;
	while (++i < ac)
	{
		if (ft_safe_atoi(av[i], &value))
		{
			if (!lst)
				lst = ft_lstnew(value);
			else
				ft_lststack(ft_lstnew(value), &lst);
			if (!lst)
				return (0);
			lst = lst->next;
		}
		else
			return (ft_lstclear(lst), NULL);
	}
	return (lst);
}
