/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:01:42 by yeohong           #+#    #+#             */
/*   Updated: 2023/02/08 15:25:33 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_one_line(char *buffer, int fd);
char	*get_result_line(char *buffer);
char	*get_next_contents(char *buffer);

char	*get_next_line(int fd)
{
	static char		*buffer[256];
	char			*result;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	buffer[fd] = get_one_line(buffer[fd], fd);
	if (buffer[fd] == 0)
		return (0);
	result = get_result_line(buffer[fd]);
	buffer[fd] = get_next_contents(buffer[fd]);
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
		read_line[read_count] = '\0';
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

	if (!buffer[0])
		return (0);
	result = (char *)malloc(sizeof(char) * (ft_strlen(buffer) + 1));
	if (!result)
		return (0);
	index = 0;
	while (buffer[index])
	{
		result[index] = buffer[index];
		index++;
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
