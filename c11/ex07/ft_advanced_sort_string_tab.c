/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 13:09:44 by yeohong           #+#    #+#             */
/*   Updated: 2022/10/17 14:33:57 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_len(char **str)
{
	int	count;

	count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		j;
	int		cnt;
	char	*tmp;

	cnt = str_len(tab);
	i = 0;
	while (i < cnt - 1)
	{
		j = 0;
		while (j < cnt - 1 - i)
		{
			if ((*cmp)(tab[j], tab[j + 1]) > 0)
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}		
		i++;
	}
}
