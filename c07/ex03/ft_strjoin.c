/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:55:03 by yeohong           #+#    #+#             */
/*   Updated: 2022/10/16 10:43:00 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	str_len1(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}

int	total_length(int size, char **strs, char *sep)
{
	int	count;
	int	i;
	int	sep_size;
	int	j;

	j = 0;
	i = 0;
	count = 0;
	sep_size = str_len1(sep);
	if (size == 0)
		return (0);
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
			j++;
		count = count + j + sep_size;
		i++;
	}
	return (count - sep_size);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		i;
	int		j;
	int		index;

	index = 0;
	i = -1;
	j = 0;
	result = (char *)malloc(sizeof(char) * (total_length(size, strs, sep) + 1));
	if (size == 0)
	{	
		result[0] = '\0';
		return (result);
	}
	while (++i < size)
	{
		j = 0;
		while (strs[i][j])
			result[index++] = strs[i][j++];
		j = 0;
		while (sep[j] && i != size - 1)
			result[index++] = sep[j++];
	}
	result[index] = 0;
	return (result);
}
