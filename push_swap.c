/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 08:13:30 by gdelhota          #+#    #+#             */
/*   Updated: 2024/12/27 09:24:51 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

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
