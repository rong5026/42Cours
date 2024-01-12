/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:04:12 by hanseuki          #+#    #+#             */
/*   Updated: 2022/10/19 22:02:48 by yeohong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		dp_init(t_board *map);
void	dp_get_solution(t_board *map);
int		get_minimum(int value1, int value2, int value3);
void	get_maximum(t_board *map, int i, int j);

int	dp_init(t_board *map)
{
	int	i;
	int	j;

	map->calculate = (int **)malloc(sizeof(int *) * map->row);
	i = 0;
	while (i < map->row)
	{
		j = 0;
		map->calculate[i] = (int *)malloc(sizeof(int) * map->col);
		while (j < map->col)
		{
			if (map->board[i + 1][j] == map->obstacle)
				map->calculate[i][j] = 0;
			else if (map->board[i + 1][j] == map->empty)
			{
				map->calculate[i][j] = 1;
				get_maximum(map, i, j);
			}
			else
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

void	dp_get_solution(t_board *map)
{
	int	i;
	int	j;
	int	a;
	int	b;
	int	c;

	i = 1;
	while (i < map->row)
	{
		j = 1;
		while (j < map->col)
		{
			if (map->calculate[i][j] == 1)
			{
				a = map->calculate[i -1][j -1];
				b = map->calculate[i -1][j];
				c = map->calculate[i][j -1];
				map->calculate[i][j] = get_minimum(a, b, c) + 1;
				get_maximum(map, i, j);
			}
			j++;
		}
		i++;
	}
}

int	get_minimum(int value1, int value2, int value3)
{
	if (value1 <= value2 && value1 <= value3)
		return (value1);
	else if (value2 <= value1 && value2 <= value3)
		return (value2);
	else
		return (value3);
}

void	get_maximum(t_board *map, int i, int j)
{
	if (map->calculate[i][j] > map->size)
	{
		map->max_p1.x = i;
		map->max_p1.y = j;
		map->size = map->calculate[i][j];
	}
}
