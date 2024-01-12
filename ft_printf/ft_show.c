/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:41:13 by yeohong           #+#    #+#             */
/*   Updated: 2022/12/12 13:31:33 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_number_count(long long number)
{
	int	count;

	if (number == 0)
		return (1);
	count = 0;
	while (number != 0)
	{
		number /= 10;
		count++;
	}
	return (count);
}

void	show_reverse(long long number)
{
	if (number > 9)
		show_reverse(number / 10);
	ft_put_char(number % 10 + '0');
}

int	get_hexnumber_count(unsigned long long number)
{
	int	count;

	if (number == 0)
		return (1);
	count = 0;
	while (number != 0)
	{
		number /= 16;
		count++;
	}
	return (count);
}

void	show_base_reverse(unsigned long long number, char *base)
{
	if (number > 15)
		show_base_reverse((number / 16), base);
	ft_put_char(base[number % 16]);
}
