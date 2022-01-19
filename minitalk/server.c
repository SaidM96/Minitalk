/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smia <smia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 06:13:50 by smia              #+#    #+#             */
/*   Updated: 2022/01/19 22:52:12 by smia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_pid = 0;

void	handler(int signum, siginfo_t *sig_info, void *context)
{
	static char		ascii;
	static int		i;

	(void) context;
	signum -= SIGUSR1;
	if (g_pid != sig_info->si_pid)
	{
		ascii = 0;
		i = 0;
		g_pid = sig_info->si_pid;
	}
	if (signum)
		ascii = ascii << 1 | 1;
	if (!signum)
		ascii = ascii << 1 | 0;
	i++;
	if (i == 8)
	{
		ft_putchar(ascii);
		i = 0;
		ascii = 0;
	}
}

int	main(void)
{
	struct sigaction	g;

	g.sa_sigaction = &handler;
	g.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &g, NULL);
	sigaction(SIGUSR2, &g, NULL);
	ft_putstr("PID = ");
	ft_putnbr(getpid());
	ft_putstr("\n");
	while (1)
		pause();
}
