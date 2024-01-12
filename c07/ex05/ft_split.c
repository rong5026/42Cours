/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:03:54 by yeohong           #+#    #+#             */
/*   Updated: 2022/10/16 10:58:18 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_charset(char *str, char *charset)
{
	while (*charset)
	{
		if (*charset == *str)
			return (1);
		charset++;
	}
	return (0);
}

int	word_count(char *str, char *charset)
{
	int		count;
	int		flag;

	flag = 0;
	count = 0;
	while (*str)
	{
		while (is_charset(str, charset) && *str)
			str++;
		while (!is_charset(str, charset) && *str++)
			flag = 1;
		if (is_charset(str, charset) && flag == 1)
		{
			count++;
			flag = 0;
		}
	}
	if (flag == 1)
		return (count + 1);
	return (count);
}

char	*make_word(char *str, int start, int last)
{
	char	*word;
	int		word_len;
	int		i;

	i = 0;
	word_len = last - start + 1;
	if (start > last)
		return (0);
	word = (char *)malloc(sizeof(char) * (word_len + 1));
	if (word == 0)
		return (0);
	while (start <= last)
		word[i++] = str[start++];
	word[i] = 0;
	return (word);
}

char	**ft_split(char *str, char *charset)
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
		while (is_charset(&str[i], charset) && str[i])
			i++;
		start = i;
		while (!is_charset(&str[i], charset) && str[i])
			i++;
		last = i - 1;
		if (str[start] != '\0')
			result[index++] = make_word(str, start, last);
	}
	result[index] = 0;
	return (result);
}
