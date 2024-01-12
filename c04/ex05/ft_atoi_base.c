/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 09:40:38 by yeohong           #+#    #+#             */
/*   Updated: 2022/10/09 20:14:48 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	str_length(char *str)
{
	int	index;

	index = 0;
	while (*str)
	{
		index++;
		str++;
	}
	return (index);
}

int	check_valid_base1(char *base)
{
	int	index;
	int	index2;

	index = 0;
	if (*base == '\0' || str_length(base) == 1)
		return (0);
	while (base[index] != '\0')
	{
		if (base[index] == '+' || base[index] == '-')
			return (0);
		else if ((base[index] >= 9 && base[index] <= 13) || base[index] == 32)
			return (0);
		index2 = index + 1;
		while (base[index2] != '\0')
		{
			if (base[index] == base[index2])
				return (0);
			index2++;
		}
		index++;
	}
	return (1);
}

int	convert_base1(char *str, char *base)
{
	int	index;

	index = 0;
	while (base[index] != '\0')
	{
		if (base[index] == *str)
			return (index);
		index++;
	}
	return (-1);
}

int	get_result(char *str, char *base, int base_count)
{
	int		sum;

	sum = 0;
	while (*str)
	{
		if (convert_base1(str, base) == -1)
			break ;
		sum = base_count * sum + convert_base1(str, base);
		str++;
	}
	return (sum);
}

int	ft_atoi_base(char *str, char *base)
{
	int			base_count;
	int			sign;

	sign = 1;
	if (check_valid_base1(base) == 0)
		return (0);
	else
	{
		base_count = str_length(base);
		while (*str)
		{
			if ((9 <= *str && *str <= 13) || *str == 32)
				str++;
			else
				break ;
		}
		while (*str && (*str == '+' || *str == '-'))
		{
			if (*str == '-')
				sign *= (-1);
			str++;
		}
		return (get_result(str, base, base_count) * sign);
	}	
}
