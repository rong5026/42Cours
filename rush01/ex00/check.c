/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 07:46:15 by youngwch          #+#    #+#             */
/*   Updated: 2022/10/09 21:11:09 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	first_second_counting(int array[4][4], int i, int j)
{
	int	x;
	int	high_building;
	int	count;

	count = 0;
	high_building = 0;
	x = 0;
	while (x < 4)
	{
		if (i == 0 && (array[x][j] > high_building))
		{
			count++;
			high_building = array[x][j];
		}
		else if (i == 1 && (array[3 - x][j] > high_building))
		{
			count++;
			high_building = array[3 - x][j];
		}
		x++;
	}
	return (count);
}

int	third_four_counting(int array[4][4], int i, int j)
{
	int	x;
	int	high_building;
	int	count;

	count = 0;
	high_building = 0;
	x = 0;
	while (x < 4)
	{
		if (i == 2 && (array[j][x] > high_building))
		{
			count ++;
			high_building = array[j][x];
		}
		else if (i == 3 && (array[j][3 - x] > high_building))
		{
			count ++;
			high_building = array[j][3 - x];
		}
		x++;
	}
	return (count);
}

int	count_building(int array[4][4], int i, int j)
{
	if (i == 0 || i == 1)
		return (first_second_counting(array, i, j));
	else
		return (third_four_counting(array, i, j));
}

void	clean(int array[4][4], int i, int j)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (x == i && y >= j)
				array[x][y] = -1;
			else if (x > i)
				array[x][y] = -1;
			y++;
		}
		x++;
	}
}

int	check_duplicate_value(int array[4][4], int i, int j, int value)
{
	int	x;

	x = 0;
	while (x < 4)
	{
		if (array[i][x] == value)
		{
			return (0);
		}
	x++;
	}
	x = 0;
	while (x < 4)
	{
		if (array[x][j] == value)
		{
			return (0);
		}
		x++;
	}
	return (1);
}
