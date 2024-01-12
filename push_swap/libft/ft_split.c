/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:29:58 by yeohong           #+#    #+#             */
/*   Updated: 2022/12/03 15:28:10 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *str, char charset)
{
	int		count;
	int		flag;

	flag = 0;
	count = 0;
	while (*str)
	{
		while ((*str == charset) && *str)
			str++;
		while ((*str != charset) && *str)
		{
			flag = 1;
			str++;
		}
		if ((*str == charset) && flag == 1)
		{
			count++;
			flag = 0;
		}
	}
	if (flag == 1)
		return (count + 1);
	return (count);
}

static void	memomry_free(char **str, int index)
{
	int	count;

	count = 0;
	while (count < index)
		free(str[count++]);
	free(str);
	return ;
}

static int	make_word(char **result, int *index, const char *s, int word_len)
{
	result[*index] = (char *)malloc(sizeof(char) * (word_len + 1));
	if (result[*index] == 0)
	{
		memomry_free(result, (*index));
		return (0);
	}
	ft_strlcpy(result[*index], s, word_len + 1);
	*index += 1;
	return (1);
}

char	**ft_split(char const *str, char charset)
{
	char	**result;
	int		i;
	int		start;
	int		last;
	int		index;

	index = 0;
	i = 0;
	result = (char **)malloc(sizeof(char *) * (word_count(str, charset) + 1));
	if (result == 0)
		return (0);
	while (str[i])
	{
		while ((str[i] == charset) && str[i])
			i++;
		start = i;
		while ((str[i] != charset) && str[i])
			i++;
		last = i - 1;
		if (str[start] != '\0')
			if (make_word(result, &index, &str[start], last - start + 1) == 0)
				return (0);
	}
	result[index] = 0;
	return (result);
}
