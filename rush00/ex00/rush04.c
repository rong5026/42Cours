/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 22:04:34 by yeohong           #+#    #+#             */
/*   Updated: 2022/10/02 16:42:17 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int		row;
	int		col;

	row = 0;
	while (row < y)
	{
		col = 0;
		while (col < x)
		{
			if (col == 0 && row == 0)
				ft_putchar('A');
			else if (col == x - 1 && row == y - 1 && x != 1 && y != 1)
				ft_putchar('A');
			else if ((col == x - 1 && row == 0) || (col == 0 && row == y - 1))
				ft_putchar('C');
			else if (row == 0 || row == y - 1 || col == 0 || col == x - 1)
				ft_putchar('B');
			else
				ft_putchar(' ');
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}
