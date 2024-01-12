/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:25:00 by yeohong           #+#    #+#             */
/*   Updated: 2022/10/01 12:07:00 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_combn(int n);
void	print_str(char *str, int n);
int		check_update(char *str, int n);

void	ft_print_combn(int n)
{
	char	str[10];
	char	min;
	int		index;

	index = 0;
	while (index < n)
	{
		min = index + '0';
		str[index] = min;
		index++;
	}
	min = 10 - n + '0';
	while (str[0] != min)
	{
		print_str(str, n);
		if (check_update(str, n) == 0)
			str[n - 1]++;
	}
	index = 0;
	while (index < n)
	{
		write(1, &str[index++], 1);
	}
}

void	print_str(char *str, int n)
{
	int	index;

	index = 0;
	while (index < n)
	{
		write(1, &str[index], 1);
		index++;
	}
	write(1, ", ", 2);
}

int	check_update(char *str, int n)
{
	int		index;
	char	match;

	index = 0;
	while (index < n)
	{
		match = 9 - (n - index -1) + '0';
		if (str[index] == match)
		{
			*(str + index -1) = *(str + index -1) + 1;
			while (index < n)
			{
				*(str + index) = *(str + index - 1) + 1;
				index++;
			}
			return (1);
		}	
		index++;
	}
	return (0);
}
