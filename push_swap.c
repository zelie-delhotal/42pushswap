/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 08:13:30 by gdelhota          #+#    #+#             */
/*   Updated: 2025/01/30 18:54:31 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	ft_lstadd_front(t_list **lst, char *content)
{
	int		value;

	if (!ft_safe_atoi(content, &value))
		return (0);
	res = lst_new(&value);
	if (!res)
		return (NULL);
	ft_lststack(lst, res);
	return (1);
}

int	main(int ac, char **av)
{
	int		i;
	t_list	lsta;

	if (ac < 2)
		return (-1);
	lsta = ft_lstnew(av[1]);
	if (!lsta)
		return (-1);
	i = 2;
	while (i < ac && ft_lstadd_front(av[i]))
		i++;
}
