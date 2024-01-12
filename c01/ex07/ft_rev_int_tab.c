/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 13:42:40 by yeohong           #+#    #+#             */
/*   Updated: 2022/10/02 13:58:55 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	index;
	int	hong;

	index = 0;
	while (index < size / 2)
	{
		hong = *(tab + index);
		*(tab + index) = *(tab - index + size - 1);
		*(tab + -index + size - 1) = hong;
		index++;
	}
}
