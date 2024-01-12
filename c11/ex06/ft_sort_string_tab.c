/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 11:33:46 by yeohong           #+#    #+#             */
/*   Updated: 2022/10/17 14:20:33 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	stringcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return ((unsigned char )*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	str_len1(char **str)
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

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		j;
	int		cnt;
	char	*tmp;

	cnt = str_len1(tab);
	i = 0;
	while (i < cnt - 1)
	{
		j = 0;
		while (j < cnt - 1 - i)
		{
			if (stringcmp(tab[j], tab[j + 1]) > 0)
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
