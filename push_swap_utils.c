/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 09:25:34 by gdelhota          #+#    #+#             */
/*   Updated: 2025/03/25 18:15:55 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	check_for_doubles(t_dll *lst)
{
	t_dll	*head;
	t_dll	*compare;

	head = lst;
	compare = lst;
	lst = lst->next;
	while (lst != head)
	{
		compare = head;
		while (lst != compare)
		{
			if (lst->content == compare->content)
			{
				ft_lstclear(lst);
				ft_error("Error\n");
			}
			compare = compare->next;
		}
		lst = lst->next;
	}
}

int	find_target_pos(int value, t_dll *dst)
{
	int		pos;
	int		min_target;
	int		target_pos;

	target_pos = 0;
	pos = -1;
	while (++pos < get_dll_size(dst))
	{
		if (value > dst->prev->content && dst->prev->content > dst->content)
			target_pos = pos;
		dst = dst->next;
	}
	min_target = INT_MAX;
	pos = -1;
	while (++pos < get_dll_size(dst))
	{
		if (dst->content == value)
		{
			ft_printf("%d\n", pos);
			return (pos);
		}
		if (dst->content > value && dst->content < min_target)
		{
			min_target = dst->content;
			target_pos = pos;
		}
		dst = dst->next;
	}
	ft_printf("value %d target pos %d\n", value, target_pos);
	return (target_pos);
}

// fills the path parameter with 4 ints
// first value is nbr of rotations to apply to lstb, negative if reversed
// second is boolean wether lsta needs the same rotation or not
// third is additional rotations to apply to lstb
// fourth is additional rotations to apply to lsta
void	get_storing_path(int *path, t_dll *node, t_dll *lstb, t_dll *lsta)
{
	int	diff;

	ft_printf("position \n");
	path[0] = find_target_pos(node->content, lstb);
	ft_printf("target \n");
	path[3] = find_target_pos(node->content, lsta);
	path[2] = 0;
	diff = ((path[3] - get_dll_size(lsta)) - (path[0] - get_dll_size(lstb)));
	if (abs(path[3] - path[0]) < abs(diff))
		diff = path[3] - path[0];
	if (path[0] > get_dll_size(lstb) / 2)
		path[0] -= get_dll_size(lstb);
	if (path[3] > get_dll_size(lsta) / 2)
		path[3] -= get_dll_size(lsta);
	path[1] = (abs(path[3]) > abs(diff % get_dll_size(lsta))
		   || abs(path[0]) > abs(diff % get_dll_size(lstb)));
	if (path[1])
	{
		if (abs(path[0]) < abs(path[3]))
		{
			path[0] = path[3];
			path[3] = 0;
			path[2] = diff;
		}
		else
			path[3] = diff;
	}
	ft_printf("%d path %d %d %d %d\n", node->content, path[0], path[1], path[2], path[3]);
	ft_printf("weight %d\n", abs(path[0]) + abs(path[2]) + abs(path[3]));
}

int	*get_optimal_storing_path(int *res, t_dll *src, t_dll *dst)
{
	int		path[4];
	t_dll	*curr_node;

	get_storing_path(res, src, src, dst);
	curr_node = src->next;
	while (curr_node != src)
	{
		get_storing_path(path, curr_node, src, dst);
		if ((abs(path[0]) + abs(path[2]) + abs(path[3])) 
			< (abs(res[0]) + abs(res[2]) + abs(res[3])))
			ft_array_copy(path, res, 4);
		curr_node = curr_node->next;
	}
	ft_printf("optimal path %d %d %d %d\n", res[0], res[1], res[2], res[3]);
	return (res);
}

void	put_away_value(int *path, t_dll **lsta, t_dll **lstb)
{
	int	i;

	i = 0;
	ft_printf("pushing path %d %d %d %d\n", path[0], path[1], path[2], path[3]);
	while (i < abs(path[0]) || i < abs(path[2]) || i < abs(path[3]))
	{
		if (i < abs(path[0]) && path[1] && path[0] > 0)
			exec("rr", lsta, lstb);
		if (i < abs(path[0]) && !path[1] && path[0] > 0)
			exec("rb", lsta, lstb);
		if (i < abs(path[0]) && path[1] && path[0] < 0)
			exec("rrr", lsta, lstb);
		if (i < abs(path[0]) && !path[1] && path[0] < 0)
			exec("rrb", lsta, lstb);
		if (i < abs(path[2]) && path[2] > 0)
			exec("rb", lsta, lstb);
		if (i < abs(path[2]) && path[2] < 0)
			exec("rrb", lsta, lstb);
		if (i < abs(path[3]) && path[3] > 0)
			exec("ra", lsta, lstb);
		if (i < abs(path[3]) && path[3] < 0)
			exec("rra", lsta, lstb);
		i++;
	}
	exec("pa", lsta, lstb);
}
