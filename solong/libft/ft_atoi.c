/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:04:46 by yeohong           #+#    #+#             */
/*   Updated: 2022/12/03 15:21:17 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_space(const char *str)
{
	if ((9 <= *str && *str <= 13) || *str == 32)
		return (1);
	return (0);
}

static int	is_number(const char *str)
{
	if ('0' <= *str && *str <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	sum;

	sum = 0;
	sign = 1;
	while (*str && is_space(str))
		str++;
	if (*str == '-')
		sign *= (-1);
	if (*str == '-' || *str == '+')
		str++;
	while (*str && is_number(str) == 1)
	{
		sum = sum * 10 + (*str - '0');
		str++;
	}
	return (sum * sign);
}
