/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 20:21:49 by yeohong           #+#    #+#             */
/*   Updated: 2022/10/04 12:59:14 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (('A' <= str[i] && str[i] <= 'Z'))
		{
			str[i] = str[i] - 'A' + 'a';
		}
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int		flag;
	char	*str2;

	flag = 0;
	str = strlowcase(str);
	str2 = str;
	while (*str)
	{
		if (('a' <= *str && *str <= 'z') || ('0' <= *str && *str <= '9'))
		{
			if (flag == 0)
			{
				flag = 1;
				if ('a' <= *str && *str <= 'z')
					*str = *str - 'a' + 'A';
			}
		}
		else
		{	
			flag = 0;
		}
		str++;
	}
	return (str2);
}
