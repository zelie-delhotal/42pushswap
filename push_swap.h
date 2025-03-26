/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 08:25:15 by gdelhota          #+#    #+#             */
/*   Updated: 2025/03/26 03:46:03 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include <limits.h>
# include "ft_printf.h"
# include "libft/libft.h"

int		get_size(t_dll *lst);
void	check_for_doubles(t_dll *lst);
int		is_sorted(t_dll *lst);
int		*get_biggest_sublist(t_dll *lst);
int		find_target_pos(int value, t_dll *dst);
int		*get_optimal_path(int *res, t_dll *src, t_dll *dst);
void	put_away_value(int *path, t_dll **lsta, t_dll **lstb);
int		exec(char *instr, t_dll **lsta, t_dll **lstb);
void	mini_push_swap(t_dll **lsta);

#endif
