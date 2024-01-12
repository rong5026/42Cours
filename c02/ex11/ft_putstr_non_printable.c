/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:39:07 by yeohong           #+#    #+#             */
/*   Updated: 2022/10/06 09:33:53 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_printable(unsigned char a)
{
	if (31 < a && a < 127)
		return (1);
	return (0);
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	char			*base;
	unsigned char	*str1;

	str1 = (unsigned char *)str;
	base = "0123456789abcdef";
	i = 0;
	while (str[i] != '\0')
	{
		if (check_printable(str1[i]))
			write(1, &str1[i], 1);
		else
		{
			write(1, "\\", 1);
			write(1, &base[str1[i] / 16], 1);
			write(1, &base[str1[i] % 16], 1);
		}
		i++;
	}
}
