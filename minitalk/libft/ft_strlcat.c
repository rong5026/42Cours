/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:21:51 by yeohong           #+#    #+#             */
/*   Updated: 2022/12/03 15:28:22 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	index;
	size_t	dest_length;
	size_t	src_length;

	dest_length = ft_strlen(dest);
	src_length = ft_strlen(src);
	if (dest_length + 1 > dstsize)
		return (dstsize + src_length);
	while (*dest)
		dest++;
	index = 0;
	while (*src && index + dest_length + 1 < dstsize)
	{
		*dest++ = *src++;
		index++;
	}
	*dest = '\0';
	return (dest_length + src_length);
}
