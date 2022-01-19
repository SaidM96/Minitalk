/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smia <smia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 06:23:54 by smia              #+#    #+#             */
/*   Updated: 2022/01/19 22:55:10 by smia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_char(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c >> i & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i--;
		usleep(500);
	}
}

void	handler(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr("wslat bslamtha\n");
}

int	check_error(char *str)
{
	int	pid;
	int	i;

	pid = ft_atoi(str);
	if (pid < 0)
		return (0);
	i = kill(pid, 0);
	if (i == -1)
		return (0);
	return (pid);
}

int	main(int ac, char **av)
{
	int		pid;
	char	*str;
	int		i;

	i = 0;
	if (ac == 3)
	{
		pid = check_error(av[1]);
		if (pid > 0)
		{
			str = av[2];
			signal(SIGUSR1, handler);
			while (str[i])
			{
				send_char(pid, str[i]);
				i++;
			}
			send_char(pid, 0);
		}
		else
			ft_putstr("incorect pid! \n");
	}
	else
		ft_putstr("Syntax error !\n");
	return (0);
}
