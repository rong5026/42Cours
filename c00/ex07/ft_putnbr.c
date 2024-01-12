/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:18:31 by yeohong           #+#    #+#             */
/*   Updated: 2022/10/01 12:06:52 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	get_length(int nb)
{
	int		index;

	index = 0;
	while (nb != 0)
	{
		index++;
		nb /= 10;
	}
	return (index);
}

void	print_number(int nb)
{
	int		length;
	int		a;
	char	result;

	a = 1;
	length = get_length(nb);
	while (length > 1)
	{
		a *= 10;
		length--;
	}
	while (a != 0)
	{
		result = ((nb / a) % 10) + '0';
		a /= 10;
		write(1, &result, 1);
	}
}

void	ft_putnbr(int nb)
{
	if (nb == 0)
		write(1, "0", 1);
	else if (nb > 0 && nb <= 2147483647)
	{
		print_number(nb);
	}
	else if (nb < 0 && nb > -2147483648)
	{
		write(1, "-", 1);
		print_number(nb * (-1));
	}
	else if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
}
