/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:07:24 by yeohong           #+#    #+#             */
/*   Updated: 2023/06/28 15:13:22 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*buffer_join(char *buffer, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

char	*next_buffer(char *buffer)
{
	int		j;
	int		i;
	char	*result;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	result = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	if (!result)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		result[j++] = buffer[i++];
	free(buffer);
	return (result);
}

char	*find_line(char *buffer)
{
	int		i;
	char	*result;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	result = ft_calloc(i + 2, sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		result[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		result[i++] = '\n';
	return (result);
}

char	*read_file(int fd, char *buffer)
{
	char	*result;
	int		byte_read;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	result = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!result)
		return (NULL);
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, result, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(result);
			return (NULL);
		}
		result[byte_read] = 0;
		buffer = join_buffer(buffer, result);
		if (ft_strchr(result, '\n'))
			break ;
	}
	free(result);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[256];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (buffer[fd])
		{
			free(buffer[fd]);
			buffer[fd] = NULL;
		}
		return (NULL);
	}
	buffer[fd] = read_file(fd, buffer[fd]);
	if (buffer[fd] == NULL)
		return (NULL);
	line = find_line(buffer[fd]);
	buffer[fd] = next_buffer(buffer[fd]);
	return (line);
}
