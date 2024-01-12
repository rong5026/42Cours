/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 21:15:54 by yeohong           #+#    #+#             */
/*   Updated: 2023/07/04 09:57:28 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_valid_check(t_game *g)
{
	map_rectangle(g);
	map_wall(g);
	map_param(g);
	map_other_parma(g);
}

void	map_rectangle(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
			j++;
		if (g->wid != j)
			print_err("not rectangle map.\n", g);
		i++;
	}
}

void	map_wall(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
		{
			if (i == 0 || i == g->hei - 1)
			{
				if (g->map[i][j] != '1')
					print_err("Not valid wall map.\n", g);
			}
			else if (j == 0 || j == g->wid - 1)
			{
				if (g->map[i][j] != '1')
					print_err("Not valid wall map.\n", g);
			}
			j++;
		}
		i++;
	}
}

void	map_param(t_game *g)
{
	if (g->p_item < 1)
		print_err("Not valid item count.\n", g);
	else if (g->player_count != 1)
		print_err("Not valid player count.\n", g);
	else if (g->exit_count != 1)
		print_err("Not valid exit count.\n", g);
}

void	map_other_parma(t_game *g)
{
	int		i;
	int		j;
	char	c;

	j = 0;
	i = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
		{
			c = g->map[i][j];
			if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
				print_err("Not valid param.\n", g);
			j++;
		}
		i++;
	}
}
