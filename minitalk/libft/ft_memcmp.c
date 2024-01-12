/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:31:51 by yeohong           #+#    #+#             */
/*   Updated: 2022/12/03 15:27:49 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s_1, const void *s_2, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			index;

	s1 = (unsigned char *)s_1;
	s2 = (unsigned char *)s_2;
	index = 0;
	if (n == 0)
		return (0);
	while (index < n)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
		index++;
	}
	if (index == n)
	{
		s1--;
		s2--;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
