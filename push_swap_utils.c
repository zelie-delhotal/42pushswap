/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 09:25:34 by gdelhota          #+#    #+#             */
/*   Updated: 2025/03/19 17:00:34 by gdelhota         ###   ########.fr       */
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
				ft_error("Error : Multiple instances of the same value in the list");
			}
			compare = compare->next;
		}
		lst = lst->next;
	}
}

int	find_target_pos(int value, t_dll *dst)
{
	int		pos;
	int		target_pos;
	int		diff;
	int		min_diff;
	t_dll	*head;

	if (dst == NULL)
		return (0);
	head = dst;
	pos = 0;
	target_pos = 0;
	min_diff = head->content - value;
	dst = dst->next;
	while (dst != head && ++pos)
	{
		diff = dst->content - value;
		if (diff < min_diff && diff >= 0)
		{
			min_diff = diff;
			target_pos = dst->content - value;
		}
	}
	return (target_pos);
}

// fills the path parameter with 4 ints
// first value is nbr of rotations to apply to src, negative if reversed
// second is boolean wether dst needs the same rotation or not
// third is additional rotations to apply to src
// fourth is additional rotations to apply to dst
void	get_storing_path(int *path, t_dll *node, t_dll *src, t_dll *dst)
{
	int	diff;

	path[0] = find_target_pos(node->content, src);
	path[3] = find_target_pos(node->content, dst);
	path[2] = 0;
	diff = (path[3] - get_dll_size(dst)) - (path[0] - get_dll_size(src));
	if (abs(path[3] - path[0]) < abs(diff))
		diff = path[3] - path[0];
	if (path[0] >= get_dll_size(src) / 2)
		path[0] -= get_dll_size(src);
	if (path[3] >= get_dll_size(dst) / 2)
		path[3] -= get_dll_size(dst);
	path[1] = (abs(path[3]) > abs(diff) || abs(path[0]) > abs(diff));
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
}
