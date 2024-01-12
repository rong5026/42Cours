/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:24:54 by yeohong           #+#    #+#             */
/*   Updated: 2022/10/15 17:17:20 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

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

void	print_string(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	if (par == 0)
		return ;
	while (par->str != 0)
	{
		print_string(par->str);
		write(1, "\n", 1);
		ft_putnbr(par->size);
		write(1, "\n", 1);
		print_string(par->copy);
		write(1, "\n", 1);
		par++;
	}	
}
