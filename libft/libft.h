/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:11:11 by gdelhota          #+#    #+#             */
/*   Updated: 2025/02/05 17:39:12 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;

int		ft_safe_atoi(const char *str, int *res);
t_list	*ft_lstnew(int content);
void	ft_lstdelone(t_list *lst);
void	ft_lstclear(t_list **lst);
t_list	*ft_lstpop(t_list *lst);
int		ft_lststack(t_list *node,  t_list *stack);
void	ft_lst_push(t_list *node, t_list *stack);

#endif
