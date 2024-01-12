/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 22:29:18 by yeohong           #+#    #+#             */
/*   Updated: 2023/07/04 10:24:48 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include "./mlx/mlx.h"
# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "./printf/ft_printf.h"

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3
# define X_EVENT_KEY_EXIT		17

# define KEY_ESC		53
# define KEY_Q			12
# define KEY_W			13
# define KEY_E			14
# define KEY_R			15
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct s_img {
	void	*item;
	void	*enemy;
	void	*play;
	void	*exit;
	void	*wall;
	void	*land;
}				t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	char	**map_check;
	int		wid;
	int		hei;
	t_img	img;
	int		p_x;
	int		p_y;
	int		p_item_cnt;
	int		p_walk;
	int		p_item;
	int		player_count;
	int		exit_count;
}				t_game;

// so_long.c
void	value_init(t_game *g);
void	game_init(t_game *g, char *map);
void	image_init(t_game *g);
void	player_init(t_game *g);

// read_file.c
void	read_map(char *file_name, t_game *g);
void	count_map_size(char *map, t_game *g);
void	count_param(char *map, t_game *g);

// image.c
void	set_image(t_game *g);
void	put_img(int h, int w, t_game *g);

// move_key.c
void	move_key(t_game *g, int m_x, int m_y);
void	end_game(t_game *g);
int		press_key(int key_code, t_game *g);
void	set_option(t_game *g, int x, int y);
void	set_value_count(t_game *g, int y, int x);

// error.c
void	print_err(char *msg, t_game *g);
int		exit_game(t_game *g);
int		get_len(char **str);
int		close_game(t_game *game);

// map_check.c
void	map_valid_check(t_game *g);
void	map_rectangle(t_game *g);
void	map_wall(t_game *g);
void	map_param(t_game *g);
void	map_other_parma(t_game *g);

// map_file.c
void	check_map_clear(t_game *g);
void	find_path(t_game *g, int y, int x);
void	check_ber_file(char *str, t_game *g);

#endif