/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:36:35 by yeohong           #+#    #+#             */
/*   Updated: 2022/10/06 14:51:32 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*str2;
	char	*to_find2;

	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		if (*str == *to_find)
		{	
			str2 = str;
			to_find2 = to_find;
			while (*to_find2)
			{
				if ((*str2 != *to_find2))
					break ;
				to_find2++;
				str2++;
			}	
			if (*to_find2 == '\0')
				return (str);
		}
		str++;
	}
	return (0);
}
