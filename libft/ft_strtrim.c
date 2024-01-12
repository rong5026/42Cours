/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:59:45 by yeohong           #+#    #+#             */
/*   Updated: 2022/12/07 14:21:56 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s2)
	{
		if (*s1 == *s2)
			return (1);
		s2++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		last;
	char	*result;

	if (!s1 || !set)
		return (0);
	start = 0;
	last = ft_strlen(s1) - 1;
	while (s1[start] && ft_strcmp(&s1[start], set))
		start++;
	if (start > last)
		return (ft_strdup(""));
	while (s1[last] && ft_strcmp(&s1[last], set) && last >= start)
		last--;
	result = (char *)malloc(sizeof(char) * (last - start + 2));
	if (!result)
		return (0);
	ft_strlcpy(result, &s1[start], last - start + 2);
	return (result);
}
