/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:51:45 by yeohong           #+#    #+#             */
/*   Updated: 2022/10/20 11:01:53 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define MAX_SIZE 2147483647

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_board
{
	t_point			max_p1;
	int				size;
	int				col;
	int				row;
	char			**board;
	int				**calculate;
	char			empty;
	char			obstacle;
	char			full;
}	t_board;

int		ft_strlen(char *str);
int		check_is_space(char ch);
int		ft_atoi(char *str);
void	ft_putstr(char *str);

int		dp_init(t_board *map);
void	dp_get_solution(t_board *map);
int		get_minimum(int value1, int value2, int value3);
void	get_maximum(t_board *map, int i, int j);

void	free_t_board(t_board *map);
void	free_calculate(t_board *map);

int		create_map(t_board *map, char *argv);
char	*read_file(char *file);
void	make_solution(t_board *map);

int		init_input_map(t_board *map);
int		is_charset(char *str, char *charset);
int		word_count(char *str, char *charset);
char	*make_word(char *str, int start, int last);
char	**ft_split(char *str, char *charset);

int		valid_map(t_board *map);
int		check_valid_map_character(char ch1, char ch2, char ch3);
int		board_row_len(t_board *map);

int		create_std_map(t_board *map, char *buff);
char	*stdin_read(void);
char	*get_duff(void);

#endif 
