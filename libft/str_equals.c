/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_equals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:39:18 by gdelhota          #+#    #+#             */
/*   Updated: 2025/03/20 22:40:00 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	str_equals(char *stra, char *strb)
{
	int	i;

	i = 0;
	while (stra[i] && stra[i] == strb[i])
		i++;
	if (stra[i] || strb[i])
		return (0);
	return (1);
}
