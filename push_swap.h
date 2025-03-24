/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 08:25:15 by gdelhota          #+#    #+#             */
/*   Updated: 2025/03/18 19:09:46 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include "ft_printf.h"

int		get_size(t_dll *lst);
int		has_no_doubles(t_dll *lst);
int		is_sorted(t_dll *lst);
void	ft_error(char *error);
int		find_target_pos(int value, t_dll *dst);
void	get_storing_path(int *path, t_dll *node, t_dll *src, t_dll *dst);

void	put_list(char *name, t_dll *lst);

#endif
