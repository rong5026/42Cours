/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:26:34 by yeohong           #+#    #+#             */
/*   Updated: 2022/10/01 08:54:58 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	convert_int_to_char(int number);

void	ft_print_comb2(void)
{
	int	first;
	int	second;

	first = -1;
	while (first++ < 98)
	{
		second = first;
		while (second++ < 99)
		{
			if (first < second)
			{
				convert_int_to_char(first);
				write(1, " ", 1);
				convert_int_to_char(second);
				if (first != 98)
				{
					write(1, ", ", 2);
				}
			}
		}
	}
}

void	convert_int_to_char(int number)
{
	char	first;
	char	second;

	if (number < 10)
	{
		first = '0';
		second = number + '0';
	}
	else
	{
		first = number / 10 + '0';
		second = number % 10 + '0';
	}
	write(1, &first, 1);
	write(1, &second, 1);
}
