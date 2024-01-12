/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:22:06 by yeohong           #+#    #+#             */
/*   Updated: 2022/10/12 09:46:06 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	long long	i;

	if (nb <= 1)
		return (0);
	if (nb == 2 || nb == 3)
		return (1);
	i = 2;
	while (i * i <= (long long)nb)
	{
		if ((long long)nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

// unsigned int	i;
// 	int				count;

// 	count = 0;
// 	i = 1;
// 	while (i <= (unsigned int)(nb / 2))
// 	{
// 		if (nb % i == 0)
// 			count++;
// 		if (count > 2)
// 			return (0);
// 		i++;
// 	}
// 	if (count == 2)
// 		return (1);
// 	return (0);
