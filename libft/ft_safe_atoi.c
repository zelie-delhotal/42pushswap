/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:42:42 by gdelhota          #+#    #+#             */
/*   Updated: 2025/01/30 19:00:11 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_safe_atoi(const char *str, int *res)
{
	int	i;
	int	sign;

	*res = 0;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		sign = 2 * (str[++i] == '-') - 1;
		if (str[i] == 0)
			return (0);
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		*res = (*res * 10) + (sign * (str[i] - '0'));
		i++;
	}
	return (str[i] == 0);
}
