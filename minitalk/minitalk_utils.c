/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smia <smia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 06:13:40 by smia              #+#    #+#             */
/*   Updated: 2022/01/17 19:04:50 by smia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	j;

	j = 0;
	i = 0;
	n = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			n = n * 10 + str[i] - 48;
			i++;
			j++;
		}
		else
			return (-1);
		if (j > 6)
			return (-1);
	}
	return (n);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(int n)
{
	char	c;

	if (n == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n = n * (-1);
		}
		if (n >= 0 && n <= 9)
		{
			c = n + '0';
			write(1, &c, 1);
		}
		if (n > 9)
		{
			ft_putnbr(n / 10);
			ft_putnbr(n % 10);
		}
	}
}
