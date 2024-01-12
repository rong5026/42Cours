/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:08:49 by yeohong           #+#    #+#             */
/*   Updated: 2022/10/15 13:59:20 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_length(char *str)
{
	int	index;

	index = 0;
	while (*str)
	{
		index++;
		str++;
	}
	return (index);
}

int	check_valid_base(char *base)
{
	int	index;
	int	index2;

	index = 0;
	if (*base == '\0' || str_length(base) == 1)
		return (0);
	while (base[index] != '\0')
	{
		if (base[index] == '+' || base[index] == '-')
			return (0);
		else if ((base[index] >= 9 && base[index] <= 13) || base[index] == 32)
			return (0);
		index2 = index + 1;
		while (base[index2] != '\0')
		{
			if (base[index] == base[index2])
				return (0);
			index2++;
		}
		index++;
	}
	return (1);
}

int	convert_base1(char *str, char *base)
{
	int	index;

	index = 0;
	while (base[index] != '\0')
	{
		if (base[index] == *str)
			return (index);
		index++;
	}
	return (-1);
}

int	get_result(char *str, char *base, int base_count, int i)
{
	int		sum;
	char	*base2;

	base2 = base;
	sum = 0;
	while (str[i])
	{
		if (convert_base1(&str[i], base2) == -1)
			break ;
		sum = base_count * sum + convert_base1(&str[i], base2);
		i++;
	}
	return (sum);
}

int	ft_atoi_base(char *str, char *base)
{
	int			base_count;
	int			sign;
	int			i;

	sign = 1;
	i = 0;
	if (check_valid_base(base) == 0)
		return (0);
	else
	{
		base_count = str_length(base);
		while (str[i] != '\0')
		{
			if (!((9 <= str[i] && str[i] <= 13) || str[i] == 32))
				break ;
			i++;
		}
		while (str[i] && (str[i] == '+' || str[i] == '-'))
		{
			if (str[i] == '-')
				sign *= (-1);
			i++;
		}
		return (get_result(str, base, base_count, i) * sign);
	}	
}
