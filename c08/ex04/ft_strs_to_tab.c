/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:54:46 by yeohong           #+#    #+#             */
/*   Updated: 2022/10/15 19:48:43 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	str_len(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		str++;
		count++;
	}
	return (count);
}

char	*str_cpy(char *str)
{
	char	*result;
	int		count;
	int		i;

	i = 0;
	count = str_len(str);
	result = (char *)malloc(sizeof(char) * (count + 1));
	if (result == 0)
		return (0);
	while (str[i])
	{
		result[i] = str[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*result;
	int			i;

	i = 0;
	result = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (result == 0)
		return (0);
	while (i < ac)
	{
		result[i].str = av[i];
		result[i].size = str_len(av[i]);
		result[i].copy = str_cpy(av[i]);
		i++;
	}
	result[i].str = 0;
	return (result);
}
