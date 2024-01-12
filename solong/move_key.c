/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:24:04 by yeohong           #+#    #+#             */
/*   Updated: 2023/07/04 10:12:52 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_key(t_game *g, int m_x, int m_y)
{
	int	y;
	int	x;

	x = g->p_x + m_x;
	y = g->p_y + m_y;
	set_value_count(g, y, x);
	if (g->map[y][x] == 'E')
	{
		g->map[y - m_y][x - m_x] = '0';
		g->map[y][x] = 'H';
		set_option(g, x, y);
	}
	else if (g->map[y][x] != '1' && g->map[y][x] != 'E')
	{
		if (g->map[y - m_y][x - m_x] != 'H')
			g->map[y - m_y][x - m_x] = '0';
		else
			g->map[y - m_y][x - m_x] = 'E';
		if (g->map[y][x] != 'E')
			g->map[y][x] = 'P';
		else
			g->map[y][x] = 'H';
		set_option(g, x, y);
	}
}

void	set_value_count(t_game *g, int y, int x)
{
	if (g->map[y][x] == 'C')
		g->p_item_cnt++;
	if (g->map[y][x] == 'E' && g->p_item == g->p_item_cnt)
		end_game(g);
}

void	set_option(t_game *g, int x, int y)
{
	g->p_x = x;
	g->p_y = y;
	g->p_walk++;
	set_image(g);
	ft_printf("%d\n", g->p_walk);
}

void	end_game(t_game *g)
{
	g->p_walk++;
	ft_printf("%s%d%s\n", "Clear!! The final step : ", 1, " steps.");
	exit_game(g);
}

int	press_key(int key_code, t_game *g)
{
	if (key_code == KEY_W)
		move_key(g, 0, -1);
	else if (key_code == KEY_A)
		move_key(g, -1, 0);
	else if (key_code == KEY_S)
		move_key(g, 0, 1);
	else if (key_code == KEY_D)
		move_key(g, 1, 0);
	else if (key_code == KEY_ESC)
		exit_game(g);
	return (0);
}
