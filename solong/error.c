/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 22:31:48 by yeohong           #+#    #+#             */
/*   Updated: 2023/07/04 10:30:37 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_err(char *msg, t_game *g)
{
	write(1, "Error\n", 6);
	write(1, msg, ft_strlen(msg));
	exit_game(g);
}

int	exit_game(t_game *g)
{
	int	i;

	i = 0;
	ft_printf("%s", "End Game.\n");
	if (g->map)
	{
		while (i < get_len(g->map))
			free(g->map[i++]);
		free(g->map);
	}
	if (g->map_check)
	{
		while (i < get_len(g->map_check))
			free(g->map_check[i++]);
		free(g->map_check);
	}
	if (g)
		free(g);
	exit(1);
}

int	close_game(t_game *game)
{
	ft_printf("%s", "End Game.\n");
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	get_len(char **str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		count++;
	}
	return (count);
}
