/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 11:25:32 by yeohong           #+#    #+#             */
/*   Updated: 2022/10/17 21:27:31 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	count;
	int	count1;

	count = 0;
	count1 = 0;
	i = 0;
	while (i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) < 0)
			count++;
		else if ((*f)(tab[i], tab[i + 1]) > 0)
			count1++;
		else
		{
			count++;
			count1++;
		}
		i++;
	}
	if (length == 0)
		return (1);
	else if (count + 1 == length || count1 + 1 == length)
		return (1);
	return (0);
}
