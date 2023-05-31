/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:24:03 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/05/30 22:31:50 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>

void ft_server_handler(int signo, siginfo_t *siginfo)
int main(int ac, char **av)
{
    struct sigaction	g_server_act;
    if (ac != 1)
    {
        ft_putstr_fd("ERROR : ", 1);
	    ft_putstr_fd("./server만 입력해주세요", 1);
	    ft_putchar_fd('\n', 1);
	    return (0);
    }
    g_server_act.sa_flags = SA_SIGINFO;
    sigemptyset(&g_server_act.sa_mask);

    ft_putstr_fd("[SERVER PID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_lf("]");

    while (1)
        sigaction(SIGUSR1, ft_server_handler)
        sigaction(SIGUSR2, ft_server_handler)
		pause();
    
}