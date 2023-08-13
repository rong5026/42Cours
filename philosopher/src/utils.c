/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:42:12 by yeohong           #+#    #+#             */
/*   Updated: 2023/08/13 21:18:52 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"


int is_space(char ch)
{
    if (ch == '\t')
        return (1);
    if (ch == '\n')
        return (1);
    if (ch == '\v')
        return (1);
    if (ch == '\f')
        return (1);
    if (ch == '\r')
        return (1);
    if (ch == ' ')
        return (1);
    return (0);
}

int check_integer_atoi(long num)
{
    if (num < -2147483648 || num > 2147483647)
        return (0);
    else
        return (1);
}

long    ft_atoi(const char *str)
{
    size_t      i;
    int         sign;
    long        result;
    i = 0;
    sign = 1;
    result = 0;
    while (str[i] != '\0' && is_space(str[i]) == 1)
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i++] == '-')
            sign *= -1;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        result *= 10;
        result += str[i] - '0';
        if (!check_integer_atoi(result * sign))
            return (-1);
        i++;
    }
    return ((int)(sign * result));
}

void    print_time(char *str, t_game *game, t_philo *philo)
{
    pthread_mutex_lock(&game->printing);
    if (!game->die)
    {
       	printf("%lu ", get_time() - game->start_time);
		printf("%d %s\n", (philo->id) + 1, str);
    }
    pthread_mutex_unlock(&game->printing);
}

void    print_dead(t_game *game, t_philo *philo)
{
    int i;

    i = 0;
    while (i < game->philo_num)
    {
        game->philo[i].alive = 1;
        i++;
    }
    pthread_mutex_lock(&game->printing);
    printf("%lu ", get_time() - game->start_time);
	printf("%d %s\n", (philo->id) + 1, "died");
    pthread_mutex_unlock(&game->printing);
}