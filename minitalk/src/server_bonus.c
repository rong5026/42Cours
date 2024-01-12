/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:54:56 by yeohong           #+#    #+#             */
/*   Updated: 2023/06/03 14:40:21 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

t_data	g_data;

void	ft_init(void)
{
	g_data.bit = 0;
	g_data.i = 0;
	g_data.pid = 0;
}

void	ft_server_handler(int signal, siginfo_t *info, void *context)
{
	(void)context;
	if (g_data.pid == 0)
	{
		g_data.pid = info->si_pid;
	}
	else if (g_data.pid != 0)
	{
		if (g_data.pid != info->si_pid)
		{
			ft_init();
			g_data.pid = info->si_pid;
		}
	}
	if (signal == SIGUSR1)
	{
		g_data.i |= (0x01 << g_data.bit);
	}
	++g_data.bit;
	if (g_data.bit == 8)
	{
		g_data.bit = 0;
		ft_putchar_fd(g_data.i, 1);
		g_data.i = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	server_act;

	(void) av;
	server_act.sa_sigaction = ft_server_handler;
	server_act.sa_flags = SA_SIGINFO;
	sigemptyset(&server_act.sa_mask);
	ft_init();
	if (ac == 1)
	{
		ft_putstr_fd("SERVER PID : ", 1);
		ft_putnbr_fd(getpid(), 1);
		ft_putstr_fd("\n", 1);
		sigaction(SIGUSR1, &server_act, NULL);
		sigaction(SIGUSR2, &server_act, NULL);
		while (1)
			pause();
	}
	else
	{
		ft_putstr_fd("ERROR : ", 1);
		ft_putstr_fd("./server만 입력해주세요\n", 1);
	}
	return (0);
}
