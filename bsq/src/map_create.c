/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 09:16:49 by yeohong           #+#    #+#             */
/*   Updated: 2022/10/19 09:16:49 by yeohong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		create_map(t_board *map, char *argv);
char	*read_file(char *file);
void	make_solution(t_board *map);

int	create_map(t_board *map, char *argv)
{
	char	*buff;

	buff = read_file(argv);
	if (buff == 0)
		return (-2);
	map->board = ft_split(buff, "\n");
	if (init_input_map(map) == -1)
		return (-1);
	if (dp_init(map) == -1)
		return (-1);
	dp_get_solution(map);
	make_solution(map);
	free(buff);
	return (0);
}

char	*read_file(char *file)
{
	int			fd;
	long long	len;
	char		*buff;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (0);
	}
	buff = (char *)malloc(sizeof(char) * MAX_SIZE);
	if (buff == 0)
		return (0);
	len = read(fd, buff, MAX_SIZE);
	if (len == -1 || len > MAX_SIZE - 1)
	{
		close(fd);
		return (0);
	}
		buff[len] = '\0';
	close(fd);
	return (buff);
}

void	make_solution(t_board *map)
{
	int	i;
	int	j;

	i = map->max_p1.x;
	while (i > map->max_p1.x - map->size)
	{
		j = map->max_p1.y;
		while (j > map->max_p1.y - map->size)
		{
			map->board[i + 1][j] = map->full;
			j--;
		}
		i--;
	}
}
