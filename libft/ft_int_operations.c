/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:29:12 by gdelhota          #+#    #+#             */
/*   Updated: 2025/03/18 16:41:51 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
