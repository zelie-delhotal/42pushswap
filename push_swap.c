/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 08:13:30 by gdelhota          #+#    #+#             */
/*   Updated: 2025/02/14 19:04:04 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	push_swap(t_dll *lsta)
{
	t_dll	*lstb;

	if (!has_no_doubles(lsta))
	{
		ft_lstclear(lsta);
		ft_error("Error");
	}
	if (is_sorted(lsta))
		return ();
	lstb = NULL;
	//check for biggest sorted sublist (not necessarilly continuous) and push it
	//find cheapest value to put away -> do it -> repeat
	//idea: use an array to store costs & have long term vision (might be computation heavy)
}

int	main(int ac, char **av)
{
	int		i;
	int		value;
	t_dll	*lst;

	if (ac < 2)
		return (0);
	lsta = NULL;
	i = 1;
	while (i < ac)
	{
		if (ft_safe_atoi(av[i], &value))
		{
			lst = ft_lststack(ft_lstnew(value), lst);
			if (!lst)
				return (0);
		}
		else
			return (ft_lstclear(lst), 0);
		i++;
	}
	push_swap(lst);
	ft_lstclear(lst);
}
