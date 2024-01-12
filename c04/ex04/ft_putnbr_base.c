/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:51:44 by yeohong           #+#    #+#             */
/*   Updated: 2022/10/09 19:53:24 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	str_len(char *str)
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

int	check_valid_base(char *base)
{
	int	index;
	int	index2;

	index = 0;
	if (*base == '\0' || str_len(base) == 1)
		return (0);
	while (base[index] != '\0')
	{
		if (base[index] == '+' || base[index] == '-')
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

void	convert_base(long long number, char *base, int base_count)
{
	if (number < base_count)
	{
		write(1, &base[number], 1);
		return ;
	}
	else
	{
		convert_base(number / base_count, base, base_count);
		write(1, &base[number % base_count], 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	long long		number;
	int				base_count;

	number = (long long)(nbr);
	if (check_valid_base(base) == 0)
		return ;
	else
	{
		base_count = str_len(base);
		if (nbr < 0)
		{
			write(1, "-", 1);
			number = number * (-1);
		}
		convert_base(number, base, base_count);
	}	
}
