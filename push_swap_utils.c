/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 09:25:34 by gdelhota          #+#    #+#             */
/*   Updated: 2025/02/14 18:35:05 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	has_no_doubles(t_dll *lst)
{
	t_dll	*head;
	t_dll	*compare;

	head = lst;
	compare = lst;
	if (lst->content == compare->content && lst != compare)
		return (0);
	lst = lst->next;
	while (lst != head)
	{
		compare = head;
		while (lst != compare)
		{
			if (lst->content == compare->content)
				return (0);
			compare = compare->next;
		}
		lst = lst->next;
	}
	return (1);
}

int	is_sorted(t_dll *lst)
{
	t_dll	*head;
	int		comp_value;

	comp_value = lst->content;
	head = lst;
	if (comp_value > lst->content)
		return (0);
	lst = lst->next;
	while (lst != head)
	{
		if (comp_value > lst->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	ft_error(char *error)
{
	int	len;

	len = 0;
	while (error[len])
		len++;
	write(2, error, len);
	exit(1);
}
