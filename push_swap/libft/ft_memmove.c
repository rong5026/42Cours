/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:43:52 by yeohong           #+#    #+#             */
/*   Updated: 2022/12/03 15:27:58 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst_tmp;
	const unsigned char	*src_tmp;
	size_t				count;

	if (!dst && !src)
		return (0);
	dst_tmp = (unsigned char *)dst;
	src_tmp = (const unsigned char *)src;
	if (dst_tmp <= src_tmp)
	{
		count = -1;
		while (++count < len)
			dst_tmp[count] = src_tmp[count];
	}
	else
	{
		count = 0;
		while (++count <= len)
			dst_tmp[len - count] = src_tmp[len - count];
	}
	return (dst);
}
