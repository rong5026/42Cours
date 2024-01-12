/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 22:28:06 by yeohong           #+#    #+#             */
/*   Updated: 2023/07/21 13:35:26 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_set(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->head = 0;
	stack_a->tail = 0;
	stack_a->size = 0;
	stack_b->head = 0;
	stack_b->tail = 0;
	stack_b->size = 0;
	if (!init_a_and_b_stack(stack_a, stack_b))
		return (0);
	return (1);
}

int	init_a_and_b_stack(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->head = init_node(0);
	if (!stack_a->head)
		return (0);
	stack_a->tail = init_node(0);
	if (!stack_a->tail)
		return (0);
	stack_a->head->next = stack_a->tail;
	stack_a->tail->prev = stack_a->head;
	stack_b->head = init_node(0);
	if (!stack_b->head)
		return (0);
	stack_b->tail = init_node(0);
	if (!stack_b->tail)
		return (0);
	stack_b->head->next = stack_b->tail;
	stack_b->tail->prev = stack_b->head;
	return (1);
}

t_node	*init_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (0);
	node->prev = 0;
	node->next = 0;
	node->elem = value;
	return (node);
}

t_node	*input_stack(t_stack *stack_a, t_stack *stack_b, int elem)
{
	t_node	*node;

	node = init_node(elem);
	if (!node)
	{
		print_error(stack_a, stack_b, "error\n");
		return (0);
	}
	if (stack_a->head->next == stack_a->tail)
	{
		stack_a->head->next = node;
		node->next = stack_a->tail;
		node->prev = stack_a->head;
		stack_a->tail->prev = node;
	}
	else
	{
		stack_a->tail->prev->next = node;
		node->prev = stack_a->tail->prev;
		stack_a->tail->prev = node;
		node->next = stack_a->tail;
	}
	return (node);
}
