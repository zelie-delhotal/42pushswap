/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:11:11 by gdelhota          #+#    #+#             */
/*   Updated: 2025/03/19 19:43:54 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_dll
{
	int				content;
	struct s_dll	*next;
	struct s_dll	*prev;
}				t_dll;

int		min(int a, int b);
int		max(int a, int b);
int		abs(int n);
int		str_equals(char *stra, char *strb);
void	ft_error(char *error);
int		ft_safe_atoi(const char *str, int *res);
t_dll	*ft_lstnew(int content);
void	ft_lstdelone(t_dll *lst);
void	ft_lstclear(t_dll *lst);
t_dll	*ft_lstpop(t_dll **lst);
t_dll	*ft_lststack(t_dll *node, t_dll *stack);
t_dll	*ft_lstpush(t_dll **node, t_dll *stack);
int		is_sorted_dll(t_dll *lst);
int		get_dll_size(t_dll *lst);

#endif
