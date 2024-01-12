/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 22:25:40 by yeohong           #+#    #+#             */
/*   Updated: 2023/07/04 10:23:55 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		ft_printf("%s", "Map is Empty.\n");
	game = malloc(sizeof(t_game));
	game_init(game, argv[1]);
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 0, &press_key, game);
	mlx_hook(game->win, X_EVENT_KEY_EXIT, 0, &close_game, game);
	mlx_loop(game->mlx);
	return (0);
}

void	game_init(t_game *g, char *map)
{
	g->mlx = mlx_init();
	value_init(g);
	image_init(g);
	read_map(map, g);
	player_init(g);
	map_valid_check(g);
	check_map_clear(g);
	check_ber_file(map, g);
	g->win = mlx_new_window(g->mlx, g->wid * 64, g->hei * 64, "so_long");
	set_image(g);
}

void	player_init(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
		{
			if (g->map[i][j] == 'P')
			{
				g->p_x = j;
				g->p_y = i;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	value_init(t_game *g)
{
	g->wid = 0;
	g->hei = 0;
	g->p_x = 0;
	g->p_y = 0;
	g->p_walk = 0;
	g->p_item_cnt = 0;
}

void	image_init(t_game *g)
{
	int		wid;
	int		hei;

	g->img.item = mlx_xpm_file_to_image(g->mlx, "./image/col.xpm", &wid, &hei);
	g->img.enemy = mlx_xpm_file_to_image(g->mlx, "./image/juk.xpm", &wid, &hei);
	g->img.play = mlx_xpm_file_to_image(g->mlx, "./image/play.xpm", &wid, &hei);
	g->img.exit = mlx_xpm_file_to_image(g->mlx, "./image/exit.xpm", &wid, &hei);
	g->img.wall = mlx_xpm_file_to_image(g->mlx, "./image/wall.xpm", &wid, &hei);
	g->img.land = mlx_xpm_file_to_image(g->mlx, "./image/land.xpm", &wid, &hei);
}
