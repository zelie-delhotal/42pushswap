/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 21:38:16 by gdelhota          #+#    #+#             */
/*   Updated: 2025/02/14 16:08:33 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dll	*ft_lstpush(t_dll *node, t_dll *stack)
{
	return (ft_lststack(ft_lstpop(node), stack));
}
