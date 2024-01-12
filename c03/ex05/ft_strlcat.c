/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:53:38 by yeohong           #+#    #+#             */
/*   Updated: 2022/10/08 12:53:15 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	str_length(char *str)
{
	unsigned int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	index;
	unsigned int	dest_length;
	unsigned int	src_length;

	dest_length = str_length(dest);
	src_length = str_length(src);
	if (dest_length + 1 > size)
	{
		return (size + src_length);
	}
	while (*dest)
	{
		dest++;
	}
	index = 0;
	while (*src && index + dest_length + 1 < size)
	{
		*dest++ = *src++;
		index++;
	}
	*dest = '\0';
	return (dest_length + src_length);
}
