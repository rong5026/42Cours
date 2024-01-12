/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_seperate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:37:27 by yeohong           #+#    #+#             */
/*   Updated: 2022/12/13 14:28:07 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_put_str(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[count])
		ft_put_char(str[count++]);
	return (count);
}

int	ft_put_u(int number)
{
	unsigned int	nbr;

	nbr = (unsigned int)number;
	show_reverse((long long)nbr);
	return (get_number_count((unsigned long long)nbr));
}

int	ft_put_d_i(int number)
{
	long long	nbr;
	int			total;

	nbr = (long long)number;
	total = 0;
	if (nbr < 0)
	{
		nbr *= (-1);
		total++;
		ft_put_char('-');
	}
	total += get_number_count(nbr);
	show_reverse(nbr);
	return (total);
}
