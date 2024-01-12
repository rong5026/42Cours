/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:07:18 by yeohong           #+#    #+#             */
/*   Updated: 2022/12/07 14:15:12 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;
	size_t	total;

	if (count == 0 && size == 0)
		return (malloc(0));
	else if (size == 0)
		return (malloc(0));
	total = count * size;
	if (total / size != count)
		return (0);
	result = malloc(total);
	if (!result)
		return (0);
	ft_bzero(result, total);
	return (result);
}
