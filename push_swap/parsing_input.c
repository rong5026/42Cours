/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:35:13 by yeohong           #+#    #+#             */
/*   Updated: 2023/07/21 13:35:15 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parsing(int argc, char **argv, t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		j;
	char	**result;
	long	num;

	i = 0;
	while (++i < argc)
	{
		result = ft_split(argv[i], ' ');
		j = -1;
		check_split(stack_a, stack_b, result);
		while (result[++j])
		{
			num = ft_atoi(result[j]);
			if (check_integer(num) && check_plus_minus(result[j]))
				input_stack(stack_a, stack_b, (int)num);
			else
			{
				free_split(result);
				print_error(stack_a, stack_b, "Error\n");
			}
		}
		free_split(result);
	}
	return (0);
}

int	check_plus_minus(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0' || !ft_isdigit(str[i]))
		return (0);
	return (1);
}

int	is_space1(char ch)
{
	if (ch == '\t')
		return (1);
	if (ch == '\n')
		return (1);
	if (ch == '\v')
		return (1);
	if (ch == '\f')
		return (1);
	if (ch == '\r')
		return (1);
	if (ch == ' ')
		return (1);
	return (0);
}
