/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:35:38 by yeohong           #+#    #+#             */
/*   Updated: 2022/12/03 15:28:30 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*h_tmp;
	char	*n_tmp;

	if (needle[0] == '\0')
		return ((char *)haystack);
	h_tmp = (char *)haystack;
	n_tmp = (char *)needle;
	i = 0;
	while (h_tmp[i] && i < len)
	{
		if (h_tmp[i] == n_tmp[0])
		{	
			j = 0;
			while (n_tmp[j] && i + j < len && (h_tmp[i + j] == n_tmp[j]))
					j++;
			if (n_tmp[j] == '\0')
				return (&h_tmp[i]);
		}
		i++;
	}
	return (0);
}
