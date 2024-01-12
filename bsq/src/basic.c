/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:50:02 by yeohong           #+#    #+#             */
/*   Updated: 2022/10/20 10:57:29 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_strlen(char *str);
int		check_is_space(char ch);
int		ft_atoi(char *str);
void	ft_putstr(char *str);

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str++, 1);
	}
	write(1, "\n", 1);
}

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

int	check_is_space(char ch)
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

int	ft_atoi(char *str)
{
	int		i;
	long	result;
	int		len;

	len = ft_strlen(str) - 3;
	i = 0;
	result = 0;
	while (i < len && check_is_space(str[i]) == 1)
		i++;
	if ((str[i] == '+' || str[i] == '-') && i < len)
	{
		if (str[i] == '-')
			return (0);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && i < len)
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return ((int)result);
}
