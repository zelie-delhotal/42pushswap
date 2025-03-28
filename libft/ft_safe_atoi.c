/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:42:42 by gdelhota          #+#    #+#             */
/*   Updated: 2025/03/18 16:33:05 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

// converts *str to int and stores the value in res
// returns 0 on failure
int	ft_safe_atoi(const char *str, int *res)
{
	int		i;
	int		sign;
	long	temp;

	temp = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		sign = 2 * (str[++i] == '-') - 1;
		if (str[i] == 0)
			return (0);
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp = (temp * 10) + (sign * (str[i] - '0'));
		if (temp > INT_MAX || temp < INT_MIN)
			return (0);
		i++;
	}
	*res = (int) temp;
	return (str[i] == 0);
}

/*#include <stdio.h>
int main (int ac, char **av)
{
	int	i;
	int	value;

	i = 0;
	while (++i < ac)
	{
		if (ft_safe_atoi(av[i], &value))
			printf("%d\n", value);
		else
			printf("error\n");
	}
}*/
