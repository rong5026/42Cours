/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:20:08 by yeohong           #+#    #+#             */
/*   Updated: 2022/10/11 10:06:47 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long long	start;
	long long	last;
	long long	result;
	long long	sum;

	if (nb < 0)
		return (0);
	start = 1;
	last = (long long)nb;
	while (start <= last)
	{
		result = (start + last) / 2;
		sum = result * result;
		if (sum == (long long)nb)
			return (result);
		else if (sum > (long long)nb)
			last = result - 1;
		else
			start = result + 1;
	}
	return (0);
}

// int			i;
// long long	sum;

// i = 0;
// sum = (long long)i * (long long)i;
// while (sum <= (long long)nb)
// {
// 	if (sum == (long long)nb)
// 		return (i);
// 	i++;
// 	sum = (long long)i * (long long)i;
// }
// return (0);
