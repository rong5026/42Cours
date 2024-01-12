/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:25:18 by yeohong           #+#    #+#             */
/*   Updated: 2022/10/12 09:47:18 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime1(int nb)
{
	long long	i;

	if (nb <= 1)
		return (-1);
	if (nb == 2 || nb == 3)
		return (nb);
	i = 2;
	while (i * i <= (long long)nb)
	{
		if ((long long)nb % i == 0)
			return (-1);
		i++;
	}
	return (nb);
}

int	ft_find_next_prime(int nb)
{
	int	result;

	while (1)
	{
		result = ft_is_prime1(nb);
		if (result != -1)
			return (result);
		nb++;
	}
}
