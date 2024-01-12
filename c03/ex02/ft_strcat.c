/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:26:54 by yeohong           #+#    #+#             */
/*   Updated: 2022/10/06 09:53:57 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int		index;

	index = 0;
	while (dest[index])
	{
		index++;
	}
	while (*src)
	{
		dest[index++] = *src;
		src++;
	}
	dest[index] = '\0';
	return (dest);
}
