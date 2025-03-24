/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_tester.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 04:29:30 by gdelhota          #+#    #+#             */
/*   Updated: 2025/03/07 04:47:20 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	put_list(char *name, t_dll *lst)
{
	t_dll	*head;

	if (lst == NULL)
	{
		ft_printf("%s : NULL\n", name);
		return ;
	}
	head = lst;
	ft_printf("liste %s:\n %d ", name, lst->content);
	lst = lst-> next;
	while (lst != head)
	{
		ft_printf("%d ", lst->content);
		lst = lst->next;
	}
	ft_printf("\n");
}
