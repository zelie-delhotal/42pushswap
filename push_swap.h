/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 08:25:15 by gdelhota          #+#    #+#             */
/*   Updated: 2025/03/25 17:16:43 by gdelhota         ###   ########.fr       */
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
int		find_target_pos(int value, t_dll *dst);
int		*get_optimal_storing_path(int *res, t_dll *src, t_dll *dst);
void	put_away_value(int *path, t_dll **lsta, t_dll **lstb);
void	exec(char *order, t_dll **lsta, t_dll **lstb);

void	put_list(char *name, t_dll *lst);

#endif
