/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 08:13:30 by gdelhota          #+#    #+#             */
/*   Updated: 2025/03/04 19:11:27 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	get_size(t_dll *lst)
{
	t_dll	*head;
	int		size;

	head = lst;
	size = 1;
	while (lst->next != head)
	{
		lst = lst->next;
		size++;
	}
	ft_printf("size : %d\n", size);
	return (size);
}

//returns an array of indexes for a sublist in ascending order
//first value of the array is its length
int	*get_sublist_indexes(t_dll *lst, int lst_size)
{
	int	*sublist;
	int	i;
	int	pos;
	int	last_number;

	sublist = malloc(lst_size * sizeof(int *) + 1);
	sublist[1] = 0;
	last_number = lst->content;
	i = 1;
	pos = 1;
	while (pos < lst_size)
	{
		lst = lst->next;
		if (lst->content > last_number)
		{
			sublist[++i] = pos;
			last_number = lst->content;
		}
		pos++;
	}
	sublist[0] = i;
	return (sublist);
}

void	push_swap(t_dll *lsta)
{
	t_dll	*lstb;
	int		*sublist_indexes;

	if (!has_no_doubles(lsta))
	{
		ft_lstclear(lsta);
		ft_error("Error");
	}
	if (is_sorted(lsta))
		return ;
	lstb = NULL;
	//check for biggest sorted sublist (not necessarilly continuous)
	sublist_indexes = get_sublist_indexes(lsta, get_size(lsta));
	int	i = 1;
	while (i <= sublist_indexes[0])
	{
		ft_printf("%d ", sublist_indexes[i]);
		i++;
	}
	free(sublist_indexes);
	ft_printf("\n");
	//push said sublist in list b
	//find cheapest value to store -> do it -> repeat
	//idea: use an array to store costs & have long term vision (might be computation heavy)
}

int	main(int ac, char **av)
{
	int		i;
	int		value;
	t_dll	*lst;

	if (ac < 2)
		return (0);
	lst = NULL;
	i = 1;
	while (i < ac)
	{
		if (ft_safe_atoi(av[i], &value))
		{
			lst = ft_lststack(ft_lstnew(value), lst);
			if (!lst)
				return (0);
			lst = lst->next;
		}
		else
			return (ft_lstclear(lst), 0);
		i++;
	}
	push_swap(lst);
	ft_lstclear(lst);
}
