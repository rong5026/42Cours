/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 11:49:32 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/10/21 13:51:23 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	if (!str)
		return (0);
	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	char	*tmp;

	if (!s)
		return (0);
	tmp = (char *)s;
	while (*tmp)
	{
		if (*tmp == (char)c)
			return (tmp);
		tmp++;
	}
	if (*tmp == (char)c)
		return (tmp);
	return (0);
}

char	*ft_strjoin(const char *cons_s1, char *s2)
{
	size_t	count;
	char	*s1;
	char	*result;

	s1 = (char *)cons_s1;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s2)
		return (0);
	result = (char *)malloc(sizeof(char) *(ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
		return (0);
	count = -1;
	while (s1[++count])
		result[count] = s1[count];
	while (*s2)
		result[count++] = *s2++;
	result[count] = 0;
	free(s1);
	return (result);
}

char	*get_one_line(char *buffer, int fd)
{
	int		read_count;
	char	*read_line;
	char	*tmp;

	read_count = 1;
	read_line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!read_line)
		return (0);
	while (read_count != 0 && !ft_strchr(buffer, '\n'))
	{
		read_count = read(fd, read_line, BUFFER_SIZE);
		if (read_count == -1)
		{
			free(read_line);
			free(buffer);
			return (0);
		}
		read_line[read_count] = 0;
		tmp = read_line;
		buffer = ft_strjoin(buffer, tmp);
	}
	free(read_line);
	return (buffer);
}

char	*get_result_line(char *buffer)
{
	char	*result;
	int		index;

	if (!buffer)
		return (0);
	result = (char *)malloc(sizeof(char) * (ft_strlen(buffer) + 1));
	if (!result)
		return (0);
	index = 0;
	while (buffer[index])
	{
		result[index] = buffer[index++];
		if (buffer[index - 1] == '\n')
			break ;
	}
	result[index] = '\0';
	return (result);
}

char	*get_next_contents(char *buffer)
{
	int		index;
	int		index2;
	char	*result;

	index = 0;
	index2 = 0;
	while (buffer[index] != '\n' && buffer[index])
		index++;
	if (!buffer[index])
	{
		free(buffer);
		return (0);
	}
	result = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - index + 1));
	if (!result)
		return (0);
	while (buffer[++index])
		result[index2++] = buffer[index];
	result[index2] = '\0';
	free(buffer);
	return (result);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*result;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	buffer = get_one_line(buffer, fd);
	if (!buffer)
		return (0);
	result = get_result_line(buffer);
	buffer = get_next_contents(buffer);
	return (result);
}
