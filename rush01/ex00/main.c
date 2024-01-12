/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:19:31 by yeohong           #+#    #+#             */
/*   Updated: 2022/10/09 21:20:11 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check_duplicate_value(int array[4][4], int i, int j, int value);
void	clean(int array[4][4], int i, int j);
int		count_building(int array[4][4], int i, int j);

int	check_answer(int array[4][4], int ans_array[4][4])
{
	int		i;
	int		j;
	char	result;

	i = -1;
	j = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (ans_array[i][j] != count_building(array, i, j))
				return (0);
	}
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			result = array[i][j] + '0';
			write(1, &result, 1);
		}
		write(1, "\n", 1);
	}
	return (1);
}

int	dfs(int array[4][4], int i, int j, int ans_array[4][4])
{
	int	value;
	int	is_answer_exist;

	value = 0;
	is_answer_exist = 0;
	while (++value < 5)
	{
		if (is_answer_exist)
			return (is_answer_exist);
		if (check_duplicate_value(array, i, j, value))
		{
			array[i][j] = value;
			if ((i == 3) && (j == 3))
				return (check_answer(array, ans_array));
			else if (j == 3)
				is_answer_exist = dfs(array, i + 1, 0, ans_array);
			else
				is_answer_exist = dfs(array, i, j + 1, ans_array);
			if (j == 3)
				clean(array, i + 1, 0);
			else
				clean(array, i, j + 1);
		}
	}
	return (is_answer_exist);
}

void	ft_rush01(int ans_array[4][4])
{
	int	array[4][4];
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			array[i][j] = -1;
			j++;
		}
		i++;
	}
	if (!dfs(array, 0, 0, ans_array))
	{
		write(1, "ERROR\n", 6);
	}
}

int	check_valid_space(char **argv, int k)
{
	if (argv[1][k] != ' ' && k < 31)
	{
		write(1, "ERROR\n", 6);
		return (0);
	}
	else
	{
		return (1);
	}
}

int	main(int argc, char **argv)
{
	int	ans_array[4][4];
	int	i;
	int	j;
	int	k;

	i = -1;
	j = -1;
	k = 0;
	if (argc != 2 || argv[1][31] != '\0')
	{
		write(1, "ERROR\n", 6);
		return (0);
	}
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			ans_array[i][j] = argv[1][k] - '0';
			if (check_valid_space(argv, k + 1) == 0)
				return (0);
			k = k + 2;
		}
	}
	ft_rush01(ans_array);
}
