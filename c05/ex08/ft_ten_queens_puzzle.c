/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:28:32 by yeohong           #+#    #+#             */
/*   Updated: 2022/10/10 21:13:37 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_duplicate(int matrix[10], int i, int value)
{
	int	k;

	k = 0;
	if (i == 0)
		return (1);
	while (--i >= 0)
	{
		if (matrix[i] == value)
			return (0);
		else if (matrix[i] == value + 1 + k)
			return (0);
		else if (matrix[i] == value - 1 - k)
			return (0);
		k++;
	}
	return (1);
}

void	print_matrix(int matrix[10])
{
	int		i;
	char	result;

	i = 0;
	while (i < 10)
	{
		result = matrix[i] + '0';
		write(1, &result, 1);
		i++;
	}
	write(1, "\n", 1);
}

void	clear(int matrix[10], int i)
{
	while (i < 10)
	{
		matrix[i] = -1;
		i++;
	}
}

int	dfs(int matrix[10], int i)
{
	int	value;
	int	count;

	count = 0;
	value = 0;
	while (value < 10)
	{
		if (check_duplicate(matrix, i, value) != 0)
		{
			matrix[i] = value;
			if (i == 9)
			{
				print_matrix(matrix);
				count++;
			}
			else
			{
				count += dfs(matrix, i + 1);
				clear(matrix, i + 1);
			}
		}
		value++;
	}
	return (count);
}

int	ft_ten_queens_puzzle(void)
{
	int	i;
	int	matrix[10];

	i = 0;
	while (i < 10)
	{
		matrix[i] = -1;
		i++;
	}
	return (dfs(matrix, 0));
}
