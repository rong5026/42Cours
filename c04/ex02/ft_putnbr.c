/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:25:35 by yeohong           #+#    #+#             */
/*   Updated: 2022/10/10 16:59:32 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_number(int nb)
{
	int		mod;
	int		div;

	div = nb / 10;
	mod = (nb % 10) + '0';
	if (nb == 0)
		return ;
	else
	{	
		print_number(div);
		write(1, &mod, 1);
	}
}

void	ft_putnbr(int nb)
{
	if (nb == 0)
	{
		write(1, "0", 1);
	}
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
