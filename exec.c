/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:34:57 by gdelhota          #+#    #+#             */
/*   Updated: 2025/03/26 03:26:17 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int exec_rotate(char *instr, t_dll **lsta, t_dll **lstb)
{
	if (str_equals(instr, "ra"))
		*lsta = (*lsta)->next;
	else if (str_equals(instr, "rb"))
		*lstb = (*lstb)->next;
	else if (str_equals(instr, "rr"))
	{
		*lsta = (*lsta)->next;
		*lstb = (*lstb)->next;
	}
	else if (str_equals(instr, "rra"))
		*lsta = (*lsta)->prev;
	else if (str_equals(instr, "rrb"))
		*lstb = (*lstb)->prev;
	else if (str_equals(instr, "rrr"))
	{
		*lsta = (*lsta)->prev;
		*lstb = (*lstb)->prev;
	}
	else
		return (0);
	return (ft_printf("%s\n", instr));
}

//executes one pushswap instruction on lists lsta and lstb
//writes the instruction in stdout
//returns a positive number on success, 0 on failure
int	exec(char *instr, t_dll **lsta, t_dll **lstb)
{
	t_dll	*temp;

	if (instr[0] == 'r')
		return (exec_rotate(instr, lsta, lstb));	
	else if (str_equals(instr, "pa"))
		ft_lstpush(lstb, lsta);
	else if (str_equals(instr, "pb"))
		ft_lstpush(lsta, lstb);
	else if (str_equals(instr, "sa"))
	{
		temp = (*lsta)->next;
		ft_lststack(ft_lstpop(&temp), lsta);
	}
	else
		return (0);
	return (ft_printf("%s\n", instr));
}
