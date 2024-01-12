/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:31:55 by yeohong           #+#    #+#             */
/*   Updated: 2022/10/16 10:42:17 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	str_length(char *str);
int	ft_atoi_base(char *str, char *base);
int	check_valid_base(char *base);
int	convert_base1(char *str, char *base);
int	get_result(char *str, char *base, int base_count, int i);

int	int_length(int nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
		count++;
	while (nbr != 0)
	{
		count++;
		nbr /= 10;
	}
	return (count);
}

int	ten_to_base_count(long long number, int base_count)
{
	int	count;

	count = 0;
	while (number >= base_count)
	{
		count++;
		number = number / base_count;
	}
	return (count + 1);
}

char	*convert_base(long long number, char *base, int base_count, int sign)
{
	char	*result;	
	int		count;

	count = ten_to_base_count(number, base_count);
	if (sign == -1)
		count++;
	result = (char *)malloc(sizeof(char) * (count + 1));
	result[count--] = 0;
	while (count >= 0 && number >= base_count)
	{
		result[count--] = base[number % base_count];
		number = number / base_count;
	}
	result[count--] = base[number];
	if (sign == -1)
		result[count] = '-';
	return (result);
}

char	*ft_putnbr_base(int nbr, char *base)
{
	long long		number;
	int				base_count;
	char			*base2;
	char			*result;
	int				count;

	base2 = base;
	number = (long long)(nbr);
	if (check_valid_base(base2) == 0)
		return (0);
	else
	{
		count = int_length(number);
		base_count = str_length(base2);
		if (number < 0)
		{
			number = -number;
			result = convert_base(number, base2, base_count, -1);
		}
		else
			result = convert_base(number, base2, base_count, 1);
		return (result);
	}	
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long	number;
	char		*str;

	if (check_valid_base(base_from) == 0)
		return (0);
	else if (check_valid_base(base_to) == 0)
		return (0);
	number = ft_atoi_base(nbr, base_from);
	str = ft_putnbr_base((int)number, base_to);
	return (str);
}
