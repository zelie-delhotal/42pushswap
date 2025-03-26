/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 02:35:12 by gdelhota          #+#    #+#             */
/*   Updated: 2025/03/26 03:42:11 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void mini_push_swap(t_dll **lsta)
{
	t_dll	**lstb;
	int		path[4];
	int		*sublist;

	lstb = malloc(sizeof(t_dll **));
	*lstb = NULL;
	while (get_dll_size(*lsta) > 3)
		exec("pb", lsta, lstb);
	sublist = get_biggest_sublist(*lsta);
	if (sublist[0] != 3)
		exec("sa", lsta, lstb);
	free(sublist);
	while (*lstb != NULL)
		put_away_value(get_optimal_path(path, *lstb, *lsta), lsta, lstb);
	free(lstb);
}

