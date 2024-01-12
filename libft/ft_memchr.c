/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:59:47 by yeohong           #+#    #+#             */
/*   Updated: 2022/12/03 15:27:44 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		c_tmp;
	size_t				count;
	const unsigned char	*s_tmp;

	count = 0;
	s_tmp = (const unsigned char *)s;
	c_tmp = (unsigned char)c;
	while (count < n)
	{
		if (*s_tmp == c_tmp)
			return ((void *)s_tmp);
		s_tmp++;
		count++;
	}
	return (0);
}
