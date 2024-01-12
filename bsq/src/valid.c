/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:07:32 by yeohong           #+#    #+#             */
/*   Updated: 2022/10/20 09:35:30 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	valid_map(t_board *map);
int	check_valid_map_character(char ch1, char ch2, char ch3);
int	board_row_len(t_board *map);

int	valid_map(t_board *map)
{
	int	i;

	i = 1;
	while (i < map->row + 1)
	{
		if (map->col != ft_strlen(map->board[i]))
			return (-1);
		i++;
	}
	return (1);
}

int	check_valid_map_character(char ch1, char ch2, char ch3)
{
	if (ch1 < 32 || ch1 > 127)
		return (0);
	if (ch2 < 32 || ch2 > 127)
		return (0);
	if (ch3 < 32 || ch3 > 127)
		return (0);
	if (ch1 == ch2)
		return (0);
	if (ch2 == ch3)
		return (0);
	if (ch3 == ch1)
		return (0);
	return (1);
}

int	board_row_len(t_board *map)
{
	int	i;

	i = 0;
	while (map->board[i] != 0)
		i++;
	if (map->row != i - 1)
		return (-1);
	else
		return (0);
}
