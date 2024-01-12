/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:31:54 by yeohong           #+#    #+#             */
/*   Updated: 2022/10/06 15:42:25 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	index;
	char			*start;

	index = 0;
	start = dest;
	while (*dest)
	{
		dest++;
	}
	while (*src && index < nb)
	{
		*dest++ = *src++;
		index++;
	}
	*dest = '\0';
	return (start);
}
