/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:34:22 by yeohong           #+#    #+#             */
/*   Updated: 2022/10/06 09:34:01 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_first(unsigned long long str)
{
	int		index;
	int		result[16];

	index = 0;
	while (index <= 15)
	{
		result[index] = str % 16;
		str = str / 16;
		index++;
	}
	index--;
	while (0 <= index)
	{
		write(1, &"0123456789abcdef"[(result[index])], 1);
		index--;
	}
	write(1, ": ", 2);
}

void	print_second(unsigned char	*str, unsigned int index, unsigned int size)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	while (count++ <= 15)
	{
		if (index <= size)
		{
			write(1, &base[(str[index]) / 16], 1);
			write(1, &base[(str[index]) % 16], 1);
			if (index % 2 == 1)
				write(1, " ", 1);
		}
		else
			break ;
		index++;
	}
	while (count++ <= 15 + 1)
	{
		write(1, "  ", 2);
		if (index++ % 2 == 1)
			write(1, " ", 1);
	}
}

void	print_third(unsigned char	*str, unsigned int index, unsigned int size)
{
	int	count;

	count = 0;
	while (count < 16 && index <= size)
	{
		if (32 <= str[index] && str[index] <= 126)
			write(1, &str[index], 1);
		else
			write(1, ".", 1);
		index++;
		count++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char		*str;
	unsigned long long	first;
	unsigned int		index;

	if (size == 0)
		return (0);
	index = 0;
	while (index * 16 <= size)
	{
		str = (unsigned char *)addr;
		first = (unsigned long long)addr;
		print_first(first + (index * 16));
		print_second(str, index * 16, size - 1);
		print_third(str, index * 16, size - 1);
		write(1, "\n", 1);
		index++;
	}
	return (0);
}
