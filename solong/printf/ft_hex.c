/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:39:16 by yeohong           #+#    #+#             */
/*   Updated: 2022/12/13 14:33:36 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_x(int number, char c)
{
	char				*base;
	unsigned int		nbr;

	nbr = (unsigned int)number;
	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	show_base_reverse(nbr, base);
	return (get_hexnumber_count(nbr));
}

int	ft_put_p(unsigned long long number)
{
	int		total;

	total = ft_put_str("0x");
	show_base_reverse(number, "0123456789abcdef");
	total += get_hexnumber_count (number);
	return (total);
}
