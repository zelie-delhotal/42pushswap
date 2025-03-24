/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 08:13:30 by gdelhota          #+#    #+#             */
/*   Updated: 2025/02/05 18:18:18 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include "ft_printf.h"

void	push_swap(t_list *lsta)
{
	ft_printf("a");
}

int	main(int ac, char **av)
{
	int		i;
	int		value;
	t_list	*lsta;

	if (ac < 2)
		return (0);
	lsta = NULL;
	i = 1;
	/*while (i < ac)
	{
		if (ft_safe_atoi(av[i], &value))
		{
			if (!ft_lststack(ft_lstnew(value), lsta))
				return (ft_lstclear(&lsta), 0);
		}
		else
			return (ft_lstclear(&lsta), 0);
		i++;
	}*/
	ft_safe_atoi(av[1], &value);
	ft_lststack(ft_lstnew(value), lsta);
	//endtest
	push_swap(lsta);
}
