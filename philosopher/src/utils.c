/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:42:12 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/08/12 14:49:05 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int ft_atoi(const char *str)
{
    int i;
    int sign;
    int result;

    i = 0;
    sign = 1;
    result = 0;
    while (str[i] == 32 || (str[i]>=9 && str[i]<=13))
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if(str[i] == '-')
            sign = -1;
        i++;
    }
    while(str[i] >='0' && str[i] <='9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (sign * result);
}


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










