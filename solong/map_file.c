/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 22:08:41 by yeohong           #+#    #+#             */
/*   Updated: 2023/07/04 10:27:45 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_path(t_game *g, int y, int x)
{
	if (x < 0 || x >= g->wid || y < 0 || y >= g->hei)
		return ;
	if (g->map_check[y][x] == '1')
		return ;
	g->map_check[y][x] = '1';
	find_path(g, y + 1, x);
	find_path(g, y - 1, x);
	find_path(g, y, x + 1);
	find_path(g, y, x - 1);
}

void	check_map_clear(t_game *g)
{
	int	i;
	int	j;

	find_path(g, g->p_y, g->p_x);
	i = 0;
	while (g->map_check[i])
	{
		j = 0;
		while (g->map_check[i][j])
		{
			if (g->map_check[i][j] == 'E' || g->map_check[i][j] == 'C')
				print_err("Not valid clear path.\n", g);
			j++;
		}
		i++;
	}	
}

void	check_ber_file(char *str, t_game *g)
{
	char	**result;

	result = ft_split(str, '.');
	if (ft_strncmp(result[1], "ber", ft_strlen(result[1])) != 0)
		print_err("Not .ber file.\n", g);
}
