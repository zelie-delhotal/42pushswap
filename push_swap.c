/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 08:13:30 by gdelhota          #+#    #+#             */
/*   Updated: 2025/02/14 16:11:23 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include "ft_printf.h"

void	push_swap(t_dll *lsta)
{
	ft_printf("a");
}

int	main(int ac, char **av)
{
	int		i;
	int		value;
	t_dll	*lsta;

	if (ac < 2)
		return (0);
	lsta = NULL;
	i = 1;
	while (i < ac)
	{
		if (ft_safe_atoi(av[i], &value))
		{
			lsta = ft_lststack(ft_lstnew(value), lsta);
			if (!lsta)
				return (0);
		}
		else
			return (ft_lstclear(lsta), 0);
		i++;
	}
	push_swap(lsta);
}
