/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 08:13:30 by gdelhota          #+#    #+#             */
/*   Updated: 2025/03/19 15:51:15 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

t_dll	*push_sublist(t_dll **src, t_dll *dst, int *sublist)
{
	int	i;
	int	j;
	int	pos;

	i = sublist[0];
	while (i > 1 && sublist[i] > sublist[i - 1])
		i--;
	pos = -1;
	j = 0;
	while (j < sublist[0])
	{
		if (++pos == sublist[i] && ++j)
		{
			dst = ft_lstpush(src, dst);
			/*put_list("lstA", *src);
			put_list("lstB", dst);*/
			if (++i > sublist[0])
				i = 1;
		}
		else
			*src = (*src)->next;
	}
	return (dst);
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
	return (res);
}

void	push_swap(t_dll *lsta)
{
	t_dll	*lstb;
	int		*sublist;

	if (!has_no_doubles(lsta))
	{
		ft_lstclear(lsta);
		ft_error("Error: multiple instances of the same value");
	}
	lstb = NULL;
	while (lsta != NULL && !is_sorted(lsta))
	{
		sublist = get_biggest_sublist(lsta);
		lstb = push_sublist(&lsta, lstb, sublist);
		put_list("A", lsta);
		put_list("B", lstb);
	}
	//find cheapest value to store -> do it -> repeat
	/*while (lstb != NULL)
	{

	}*/
	free(sublist);
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
	put_list("initiale", lst);
	push_swap(lst);
	ft_lstclear(lst);
}
