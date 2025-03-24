/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:11:11 by gdelhota          #+#    #+#             */
/*   Updated: 2025/02/14 16:09:55 by gdelhota         ###   ########.fr       */
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

int		ft_safe_atoi(const char *str, int *res);
t_dll	*ft_lstnew(int content);
void	ft_lstdelone(t_dll *lst);
void	ft_lstclear(t_dll *lst);
t_dll	*ft_lstpop(t_dll *lst);
t_dll	*ft_lststack(t_dll *node,  t_dll *stack);
t_dll	*ft_lst_push(t_dll *node, t_dll *stack);

#endif
