/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:08:15 by yeohong           #+#    #+#             */
/*   Updated: 2022/10/19 22:03:00 by yeohong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	free_t_board(t_board *map);
void	free_calculate(t_board *map);

void	free_t_board(t_board *map)
{
	int	i;

	i = 0;
	while (map->board[i])
	{
		free(map->board[i]);
		i++;
	}
	if (map->board != 0)
		free(map->board);
}

void	free_calculate(t_board *map)
{
	int	i;

	i = 0;
	while (i < map->row)
	{
		if (map->calculate[i] != 0)
			free(map->calculate[i]);
		i++;
	}
	if (map->calculate != 0)
		free(map->calculate);
}
