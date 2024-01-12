/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:50:39 by yeohong           #+#    #+#             */
/*   Updated: 2022/12/03 15:28:00 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp;
	size_t			count;

	count = 0;
	tmp = (unsigned char *)b;
	while (count < len)
		tmp[count++] = (unsigned char)c;
	return (b);
}
