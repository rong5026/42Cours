/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 22:05:32 by yeohong           #+#    #+#             */
/*   Updated: 2022/10/02 17:07:35 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int a, int b);
int		change_char_to_int(char input[]);

int	main(int argc, char *argv[])
{
	int	first;
	int	second;

	if (argc == 3)
	{
		first = change_char_to_int(argv[argc - 2]);
		second = change_char_to_int(argv[argc - 1]);
		if (first > 0 && second > 0)
		{
			rush(first, second);
		}
	}
	return (0);
}

int	change_char_to_int(char input[])
{
	long long	result;

	result = 0;
	while (*input != '\0')
	{
		if (*input < '0' || *input > '9')
			return (-1);
		result = result * 10 + (*input - '0');
		input++;
	}
	if (result > 2147483647)
		return (-1);
	else
		return (result);
}
