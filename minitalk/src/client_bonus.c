/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:55:02 by yeohong           #+#    #+#             */
/*   Updated: 2023/06/03 13:20:24 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_client_sender(int pid, char *msg)
{
	int	bit;
	int	i;

	i = 0;
	while (msg[i] != '\0')
	{
		bit = 0;
		while (bit < 8)
		{
			if ((msg[i] & (0x01 << bit)) != 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			bit++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
	{
		ft_putstr_fd("./client (PID) (TEXT) 형식으로 입력해주세요.\n", 1);
		return (0);
	}
	else
	{
		pid = ft_atoi(av[1]);
		ft_client_sender(pid, av[2]);
		ft_client_sender(pid, "\n");
	}
	return (0);
}
