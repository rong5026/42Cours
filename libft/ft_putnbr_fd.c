/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:06:55 by yeohong           #+#    #+#             */
/*   Updated: 2022/12/03 15:28:06 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	get_length(int nb)
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

static void	print_number(int nb, int fd)
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
		write(fd, &result, 1);
	}
}

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == 0)
	{
		write(fd, "0", 1);
	}
	else if (nb > 0 && nb <= 2147483647)
	{
		print_number(nb, fd);
	}
	else if (nb < 0 && nb > -2147483648)
	{
		write(fd, "-", 1);
		print_number(nb * (-1), fd);
	}
	else if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
}
