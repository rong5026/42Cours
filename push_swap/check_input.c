/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:08:58 by yeohong           #+#    #+#             */
/*   Updated: 2023/07/21 13:35:53 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_number(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '+' || str[0] == '-'
		|| ft_isdigit(str[0]) || str[0] == ' ')
		i++;
	else
		return (0);
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i - 1] != ' ')
				return (0);
		}
		else if (!ft_isdigit(str[i]) && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

void	check_split(t_stack *stack_a, t_stack *stack_b, char **result)
{
	int	i;

	i = 0;
	while (result[i])
		i++;
	if (i == 0)
	{
		free_split(result);
		print_error(stack_a, stack_b, "Error\n");
	}
}

int	check_integer(long num)
{
	if (num < -2147483648 || num > 2147483647)
		return (0);
	else
		return (1);
}

void	check_duplicate(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node_i;
	t_node	*node_j;

	node_i = stack_a->head->next;
	while (node_i != stack_a->tail)
	{
		node_j = stack_a->head->next;
		while (node_j != node_i)
		{
			if (node_j->elem == node_i->elem)
				print_error(stack_a, stack_b, "Error\n");
			node_j = node_j ->next;
		}
		node_i = node_i->next;
	}
}

int	check_already_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;

	if (stack_b)
	{
		if (stack_b->head->next != stack_b->tail)
			return (0);
	}
	node = stack_a->head->next;
	while (node->next != stack_a->tail)
	{
		if (node->elem > node->next->elem)
			return (0);
		node = node->next;
	}
	return (1);
}
