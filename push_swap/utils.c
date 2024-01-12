/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:34:05 by yeohong           #+#    #+#             */
/*   Updated: 2023/07/21 13:34:24 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	t_node	*node;
	int		size;

	size = 0;
	node = stack->head->next;
	while (node != stack->tail)
	{
		size++;
		node = node->next;
	}
	stack->size = size;
	return (size);
}

int	get_min_index(t_stack *stack_a)
{
	t_node	*node;
	int		min;
	int		i;
	int		pos;

	i = 0;
	pos = 0;
	node = stack_a->head->next;
	min = node->index;
	while (node != stack_a->tail)
	{
		if (node->index < min)
		{
			min = node->index;
			pos = i;
		}
		i++;
		node = node->next;
	}
	return (pos);
}

int	get_top_index(t_stack *stack_a)
{
	return (stack_a->head->next->index);
}

int	abs(int a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
