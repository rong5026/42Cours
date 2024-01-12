/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:40:48 by yeohong           #+#    #+#             */
/*   Updated: 2022/10/13 18:19:57 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int			*result;
	long long	i;

	if (min >= max)
		return (0);
	i = 0;
	result = (int *)malloc(sizeof(int) * (max - min));
	while (min < max)
	{
		result[i++] = min;
		min++;
	}
	return (result);
}
// #include <stdio.h>
// int main()
// {
// 	printf("%d",get_len(0,4));
// }
