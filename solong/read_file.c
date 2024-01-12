/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:03:57 by yeohong           #+#    #+#             */
/*   Updated: 2023/07/04 01:07:36 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(char *file_name, t_game *g)
{
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		ft_printf("Error\n");
		exit(1);
	}
	line = get_next_line(fd);
	count_map_size(line, g);
	count_param(line, g);
	g->map = ft_split(line, '\n');
	g->map_check = ft_split(line, '\n');
	free(line);
}

void	count_map_size(char *map, t_game *g)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		if (g->wid == 0 && map[i] == '\n')
			g->wid = i;
		if (map[i] == '\n')
			count++;
		i++;
	}
	g->hei = count + 1;
}

void	count_param(char *map, t_game *g)
{
	int	i;
	int	itme_count;
	int	player_count;
	int	exit_count;

	i = 0;
	exit_count = 0;
	itme_count = 0;
	player_count = 0;
	while (map[i])
	{
		if (map[i] == 'C')
			itme_count++;
		else if (map[i] == 'P')
			player_count++;
		else if (map[i] == 'E')
			exit_count++;
		i++;
	}
	g->p_item = itme_count;
	g->player_count = player_count;
	g->exit_count = exit_count;
}
