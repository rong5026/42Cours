/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:14:02 by yeohong           #+#    #+#             */
/*   Updated: 2022/10/20 11:07:06 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	result_print(t_board map)
{
	int	k;

	k = 1;
	while (map.board[k])
	{
		ft_putstr(map.board[k]);
		k++;
	}
}

void	sub_main(t_board *map, char **argv, int i)
{
	int		read;

	read = create_map(&map[i], argv[i + 1]);
	if (read == -2)
	{
		write(1, "map error\n", 10);
	}
	else if (read == -1)
	{
		write(1, "map error\n", 10);
		free_t_board(map + i);
	}
	else
	{
		if (map[i].size > 0)
			result_print(map[i]);
		else
			write(1, "map error\n", 10);
		free_calculate(map + i);
		free_t_board(map + i);
	}
}

void	sub_std_main(t_board *map)
{
	char	*duff;
	int		read;

	duff = get_duff();
	if (duff == 0)
		return ;
	read = create_std_map(&map[0], duff);
	if (read == -2)
		write(1, "map error\n", 10);
	else if (read == -1)
	{
		write(1, "map error\n", 10);
		free_t_board(map + 0);
	}
	else
	{
		if (map[0].size > 0)
			result_print(map[0]);
		else
			write(1, "map error\n", 10);
		free_calculate(map + 0);
		free_t_board(map + 0);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_board	*map;

	if (argc != 1)
	{
		i = 0;
		map = (t_board *)malloc(sizeof(t_board) * (argc - 1));
		if (map == 0)
			return (0);
		while (i < argc - 1)
		{
			sub_main(map, argv, i);
			i++;
		}
		free(map);
	}
	else
	{
		map = (t_board *)malloc(sizeof(t_board) * 1);
		if (map == 0)
			return (0);
		sub_std_main(map);
		free(map);
	}
}
