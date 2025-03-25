/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 08:13:30 by gdelhota          #+#    #+#             */
/*   Updated: 2025/03/25 22:07:52 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//returns an array of indexes for a sublist in ascending order
//first value of the array is its length
int	*get_sublist_indexes(t_dll *lst, int lst_size, int start_pos)
{
	int	*sublist;
	int	i;
	int	pos;
	int	last_number;

	sublist = malloc(lst_size * sizeof(int *) + 1);
	sublist[1] = start_pos;
	last_number = lst->content;
	i = 1;
	pos = 1;
	while (pos < lst_size)
	{
		lst = lst->next;
		if (lst->content > last_number)
		{
			sublist[++i] = (pos + start_pos) % lst_size;
			last_number = lst->content;
		}
		pos++;
	}
	sublist[0] = i;
	return (sublist);
}

int	*get_biggest_sublist(t_dll *lst)
{
	int		i;
	int		*sublist;
	int		*res;
	t_dll	*head;

	res = get_sublist_indexes(lst, get_dll_size(lst), 0);
	head = lst;
	lst = lst->next;
	i = 1;
	while (lst != head)
	{
		sublist = get_sublist_indexes(lst, get_dll_size(lst), i);
		if (sublist[0] > res[0])
		{
			free(res);
			res = sublist;
		}
		else
			free(sublist);
		lst = lst->next;
		i++;
	}
	return (res);
}

int	array_contains(int *array, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == value)
			return (1);
		i++;
	}
	return (0);
}

void	push_swap(t_dll **lsta)
{
	t_dll	**lstb;
	int		*sublist;
	int		i;
	int		path[4];

	check_for_doubles(*lsta);
	lstb = malloc(sizeof(t_dll **));
	*lstb = NULL;
	sublist = get_biggest_sublist(*lsta);
	i = 0;
	while (get_dll_size(*lsta) > sublist[0])
	{
		if (array_contains(&sublist[1], sublist[0], i))
			exec("ra", lsta, lstb);
		else
			exec("pb", lsta, lstb);
		i++;
	}
	free(sublist);
	while (*lstb != NULL)
		put_away_value(get_optimal_path(path, *lstb, *lsta), lsta, lstb);
	while ((*lsta)->content > (*lsta)->prev->content)
		exec("ra", lsta, lstb);
	free(lstb);
}

int	main(int ac, char **av)
{
	t_dll	*lst;

	lst = ft_dll_builder(ac, av);
	if (!lst)
		ft_error("Error");
	push_swap(&lst);
	ft_lstclear(lst);
}
