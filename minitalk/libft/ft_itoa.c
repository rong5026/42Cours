/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:19:30 by yeohong           #+#    #+#             */
/*   Updated: 2022/12/03 15:21:51 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	number_count(long long number)
{
	int	count;

	count = 0;
	if (number < 0)
		count = 1;
	if (number == 0)
		return (1);
	while (number != 0)
	{
		count++;
		number /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long long	tmp;
	int			count;
	char		*result;

	count = number_count(n);
	if (n < 0)
		tmp = (long long)n * (-1);
	else
		tmp = (long long)n;
	result = (char *)malloc(sizeof(char) * (count + 1));
	if (!result)
		return (0);
	result[count] = 0;
	while (count > 0)
	{
		result[count - 1] = (char)((tmp % 10) + '0');
		count--;
		tmp /= 10;
	}
	if (n < 0)
		result[0] = '-';
	return (result);
}
