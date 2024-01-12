/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:52:59 by yeohong           #+#    #+#             */
/*   Updated: 2023/07/04 09:57:16 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(int h, int w, t_game *g)
{
	mlx_put_image_to_window(g->mlx, g->win, g->img.land, w * 64, h * 64);
	if (g->map[h][w] == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->img.wall, w * 64, h * 64);
	else if (g->map[h][w] == 'H')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.exit, w * 64, h * 64);
		mlx_put_image_to_window(g->mlx, g->win, g->img.play, w * 64, h * 64);
	}
	else if (g->map[h][w] == 'C')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.item, w * 64, h * 64);
	}
	else if (g->map[h][w] == 'P')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.play, w * 64, h * 64);
	}
	else if (g->map[h][w] == 'E')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.exit, w * 64, h * 64);
	}
	else
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.land, w * 64, h * 64);
	}
}

void	set_image(t_game *g)
{
	int		hei;
	int		wid;

	hei = 0;
	while (hei < g->hei)
	{
		wid = 0;
		while (wid < g->wid)
		{
			put_img(hei, wid, g);
			wid++;
		}
		hei++;
	}
}
