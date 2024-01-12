/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:36:16 by yeohong           #+#    #+#             */
/*   Updated: 2022/12/03 15:27:53 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dst_tmp;
	const unsigned char	*str_tmp;
	size_t				count;

	if (!dst && !src)
		return (0);
	count = 0;
	dst_tmp = (unsigned char *)dst;
	str_tmp = (const unsigned char *)src;
	while (count < n)
	{
		dst_tmp[count] = str_tmp[count];
		count++;
	}
	return (dst);
}
