/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:32:22 by yeohong           #+#    #+#             */
/*   Updated: 2022/10/20 11:01:53 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		create_std_map(t_board *map, char *buff);
char	*stdin_read(void);
char	*get_duff(void);

int	create_std_map(t_board *map, char *buff)
{
	if (buff == 0)
		return (-2);
	map->board = ft_split(buff, "\n");
	if (init_input_map(map) == -1)
		return (-1);
	if (dp_init(map) == -1)
		return (-1);
	dp_get_solution(map);
	make_solution(map);
	free(buff);
	return (0);
}

char	*stdin_read(void)
{
	char	*buff;
	char	text;
	int		size;

	size = 0;
	buff = (char *)malloc(sizeof(char) * MAX_SIZE);
	if (buff == 0)
		return (0);
	while (read(0, &text, 1) > 0)
	{
		buff[size] = text;
		size++;
	}
	buff[size] = '\0';
	return (buff);
}

char	*get_duff(void)
{
	char	*duff;

	duff = stdin_read();
	if (duff == 0)
	{
		write(1, "map error\n", 10);
		return (0);
	}
	return (duff);
}
