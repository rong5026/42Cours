/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:23:12 by yeohong           #+#    #+#             */
/*   Updated: 2022/12/03 15:28:35 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	count;
	size_t	s_len;

	s_len = ft_strlen(s);
	count = 0;
	if (s_len < start)
		return (ft_strdup(""));
	else if (s_len - start < len)
		result = (char *)malloc(sizeof(char) * (s_len - start + 1));
	else
		result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	while (count < len && s[start + count] && (s_len >= start))
	{
		result[count] = s[start + count];
		count++;
	}
	result[count] = '\0';
	return (result);
}
