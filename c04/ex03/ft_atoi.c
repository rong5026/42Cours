/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:30:42 by yeohong           #+#    #+#             */
/*   Updated: 2022/10/10 15:25:36 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char *str)
{
	if ((9 <= *str && *str <= 13) || *str == 32)
		return (1);
	return (0);
}

int	is_number(char *str)
{
	if ('0' <= *str && *str <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	sum;

	sum = 0;
	sign = 1;
	while (*str)
	{
		if (is_space(str) == 0)
			break ;
		str++;
	}
	while (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign *= (-1);
		str++;
	}
	while (*str && is_number(str) == 1)
	{
		sum = sum * 10 + (*str - '0');
		str++;
	}
	return (sum * sign);
}
