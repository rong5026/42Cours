#include "get_next_line.h"
#include <stdio.h>

// utils
size_t	ft_strlen(char *s, int only_null)
{
	size_t	return_value;

	return_value = 0;
	if (only_null)
	{
		while (s && *s)
		{
			return_value++;
			s++;
		}
		return (return_value);
	}
	while (s && (*s && *s != '\n'))
	{
		return_value++;
		s++;
	}
	return (return_value);
}


char	*ft_strjoin(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	int		return_value_i;
	int		s_i;
	char	*return_value;

	s_i = 0;
	return_value_i = 0;
	s1_len = ft_strlen(s1, 1);
	s2_len = ft_strlen(s2, 1);
	return_value = (char *) malloc (sizeof (char) * (s1_len + s2_len) + 1);
	if (!return_value)
		return ((void *)0);
	while (return_value_i < s1_len)
		return_value[return_value_i++] = s1[s_i++];
	s_i = 0;
	while (return_value_i < s2_len + s1_len)
	{
		return_value[return_value_i] = s2[s_i];
		return_value_i++;
		s_i++;
	}
	return_value[return_value_i] = '\0';
	return (return_value);
}

char	*ft_strdup(const char *s1)
{
	char	*copy;
	char	*ret;
	int		len;

	len = 0;
	while (s1[len])
		len++;
	copy = (char *) malloc (len * sizeof (char) + 1);
	if (!copy)
		return ((void *)0);
	ret = copy;
	while (*s1)
	{
		*copy = *s1;
		copy++;
		s1++;
	}
	*copy = '\0';
	return (ret);
}

int	ft_strchr(const char *s, int c)
{
	int		return_value;
	char	*char_s;

	char_s = (char *) s;
	return_value = 0;
	while (*char_s != '\0')
	{
		if (*char_s == (char)c)
		{
			return_value = 1;
			break ;
		}
		char_s++;
	}
	if ((char)c == 0)
		return (0);
	return (return_value);
}


// get_next_line
int	is_invalid_input(int *readsize, char **backup, int fd, char *buf)
{
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (1);
	*readsize = read(fd, buf, BUFFER_SIZE);
	if (*readsize == -1)
	{
		free(*backup);
		*backup = NULL;
		return (1);
	}
	if (*readsize == 0 && !(*backup)) // !
		return (1);
	return (0);
}

int	join_buf_and_backup(char **backup, char buf[])
{
	char *tmp;

	if (!(*backup) || !(**backup)) // !
		*backup = ft_strdup("");
	tmp = ft_strjoin(*backup, buf);
	if (!tmp)
	{
		free(*backup);
		*backup = NULL;
		return (0);
	}
	free(*backup);
	*backup = NULL;
	*backup = tmp; //!
	return (1);
}

int	copy_to_return(char **backup, int readsize, char **return_value)
{
	int	idx;

	idx = 0;
	*return_value = malloc (ft_strlen(*backup, 0) + ft_strchr(*backup, '\n') + 1);
	if (!(*return_value))
	{
		*backup = NULL;
		free(*backup);
		if (*return_value)
			free(*return_value);
	}
	while ((*backup)[idx])
	{
		(*return_value)[idx] = (*backup)[idx];
		if ((*backup)[idx] == '\n')
		{
			idx ++ ;
			break ;
		}
		idx ++;
	}
	(*return_value)[idx] = '\0';
	if (readsize == 0 && (!(*backup) || !(**backup)))
	{
		free(*backup);
		*backup = NULL;
		return (0);
	}
	return (1);
}

int make_new_backup(char **new_backup, char **backup)
{
	int	backup_idx;
	int	new_backup_idx;
	int backup_len;

	backup_idx = ft_strlen(*backup, 0) + 1; //!
	new_backup_idx = 0;
	backup_len = ft_strlen(*backup, 1);
	while (backup_idx < backup_len)
	{
		(*new_backup)[new_backup_idx] = (*backup)[backup_idx];
		backup_idx ++;
		new_backup_idx++;
	}
	(*new_backup)[new_backup_idx] = '\0'; 
	free(*backup); // !
	*backup = NULL;
	*backup = *new_backup;
	if (!(**new_backup))
	{
		free(*backup);
		*backup = NULL;
	}
	return (1);
}
char *get_next_line(int fd)
{
	static char *backup;
	char *new_backup;
	int	readsize;
	char *return_value;
	char buf[BUFFER_SIZE + 1];

	if (is_invalid_input(&readsize, &backup,fd, buf))
		return ((void *) 0);
	while (readsize > 0) //!
	{
		buf[readsize] = 0;
		if (!join_buf_and_backup(&backup, buf))
			return ((void *) 0);
		if (ft_strchr(backup, '\n'))
			break ;
		readsize = read(fd, buf, BUFFER_SIZE);
	}
	if (!copy_to_return(&backup, readsize, &return_value))
		return ((void *) 0);
	new_backup = malloc (ft_strlen(backup, 1) - ft_strlen(backup, 0));
	if (!new_backup)
	{	
		free(backup);
		backup = NULL;
		free(return_value);
		return ((void *)0);
	}
	make_new_backup(&new_backup, &backup);
	return (return_value);
}
#include <fcntl.h>
#include <stdio.h>
int main(void)
{
	int fd = open("../hello.txt", O_RDONLY);
	char *s = get_next_line(fd);
	while (s)
	{
		printf("%s", s);
		s = get_next_line(fd);
	}
}