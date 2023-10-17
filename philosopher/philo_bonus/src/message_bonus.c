/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 23:20:05 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/10/18 00:17:13 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	sem_print(char *message, t_monitor *monitor)
{
	sem_wait(monitor->sem_print);
	printf("%s\n", message);
	sem_post(monitor->sem_finish);
}
