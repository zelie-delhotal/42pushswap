/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 08:13:30 by gdelhota          #+#    #+#             */
/*   Updated: 2025/03/25 17:17:57 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_sublist(t_dll **lsta, t_dll **lstb, int *sublist)
{
	int	i;
	int	j;
	int	pos;

	i = sublist[0];
	while (i >= 1 && sublist[i] > sublist[i - 1])
		i--;
	pos = -1;
	j = 0;
	while (j < sublist[0])
	{
		if (++pos == sublist[i] && ++j)
		{
			if (!is_sorted_dll(*lsta))
				exec("pb", lsta, lstb);
			if (++i > sublist[0])
				i = 1;
		}
		else
			exec("ra", lsta, lstb);
	}
}

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
	int	c = 0;
	ft_printf("sublist:");
	while (++c <= res[0])
	{
		ft_printf("%d ", res[c]);
	}
	ft_printf("\n");
	return (res);
}

void	push_swap(t_dll **lsta)
{
	t_dll	**lstb;
	int		*sublist;
	int		storing_path[4];

	check_for_doubles(*lsta);
	lstb = malloc(sizeof(t_dll **));
	*lstb = NULL;
	while (!is_sorted_dll(*lsta))
	{
		sublist = get_biggest_sublist(*lsta);
		push_sublist(lsta, lstb, sublist);
	}
	if (sublist)
		free(sublist);
	while (*lstb != NULL)
	{
		//get_optimal_storing_path(storing_path, *lstb, *lsta);
		//ft_printf("optimal path %d %d %d %d\n", storing_path[0], storing_path[1], storing_path[2], storing_path[3]);
		put_away_value(get_optimal_storing_path(storing_path, *lstb, *lsta), lsta, lstb);
		if ((*lsta)->content > (*lsta)->next->content)
			exec("ra", lsta, lstb);
	}
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
	put_list("initiale", lst);
	push_swap(&lst);
	put_list("finale", lst);
	ft_lstclear(lst);
}
