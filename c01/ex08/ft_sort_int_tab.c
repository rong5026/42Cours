/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:00:34 by yeohong           #+#    #+#             */
/*   Updated: 2022/10/02 14:25:51 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	index1;
	int	index2;
	int	hong;

	index1 = 0;
	index2 = 0;
	while (index1 < size)
	{
		index2 = 0;
		while (index2 < size - index1 - 1)
		{
			if (*(tab + index2) > *(tab + index2 + 1))
			{
				hong = *(tab + index2);
				*(tab + index2) = *(tab + index2 + 1);
				*(tab + index2 +1) = hong;
			}
			index2++;
		}
		index1++;
	}
}
