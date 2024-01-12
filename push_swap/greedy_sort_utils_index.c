/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_sort_utils_index.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:13:54 by yeohong           #+#    #+#             */
/*   Updated: 2023/07/21 13:35:42 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_max_index(t_stack *stack)
{
	t_node	*node;
	int		max;

	node = stack->head->next;
	max = node->index;
	while (node != stack->tail)
	{
		if (node->index > max)
			max = node->index;
		node = node->next;
	}
	return (max);
}

int	get_stack_min_index(t_stack *stack)
{
	t_node	*node;
	int		min;

	node = stack->head->next;
	min = node->index;
	while (node != stack->tail)
	{
		if (node->index < min)
			min = node->index;
		node = node->next;
	}
	return (min);
}

int	find_max_position(t_stack *stack_a, int max_index)
{
	t_node	*node;
	int		i;

	i = 1;
	node = stack_a->head->next;
	while (node != stack_a->tail)
	{
		if (node->index == max_index)
			break ;
		node = node->next;
		i++;
	}
	return (get_half_index(stack_size(stack_a), i));
}

int	find_min_position(t_stack *stack_a, int min_index)
{
	t_node	*node;
	int		i;

	i = 0;
	node = stack_a->head->next;
	while (node != stack_a->tail)
	{
		if (node->index == min_index)
			break ;
		node = node->next;
		i++;
	}
	return (get_half_index(stack_size(stack_a), i));
}

int	find_mid_position(t_stack *stack_a, int b_index)
{
	t_node	*node;
	int		i;

	i = 1;
	node = stack_a->head->next;
	while (node->next)
	{
		if (node->next == stack_a->tail)
		{
			if (node->index < b_index && b_index < stack_a->head->next->index)
				break ;
			node = stack_a->head;
		}
		else
		{
			if (node->index < b_index && b_index < node->next->index)
				break ;
		}
		i++;
		node = node->next;
	}
	return (get_half_index(stack_size(stack_a), i));
}
