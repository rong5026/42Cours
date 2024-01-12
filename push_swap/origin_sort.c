/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   origin_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:35:20 by yeohong           #+#    #+#             */
/*   Updated: 2023/07/21 13:35:20 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stack_a)
{
	if (stack_a->head->next->elem > stack_a->tail->prev->elem)
		cmd_swap(stack_a->head, stack_a->tail, "sa\n");
}

void	sort_three(t_stack *stack_a)
{
	int	a;
	int	b;
	int	c;

	a = stack_a->head->next->elem;
	b = stack_a->head->next->next->elem;
	c = stack_a->tail->prev->elem;
	if (a > b && a > c)
	{
		cmd_rotate(stack_a->head, stack_a->tail, "ra\n");
		if (b > c)
			cmd_swap(stack_a->head, stack_a->tail, "sa\n");
	}
	else if (b > c && b > a)
	{
		cmd_reverse_rotate(stack_a->head, stack_a->tail, "rra\n");
		if (c > a)
			cmd_swap(stack_a->head, stack_a->tail, "sa\n");
	}
	else
	{
		if (a > b)
			cmd_swap(stack_a->head, stack_a->tail, "sa\n");
	}
}

void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	int	min;

	min = get_min_index(stack_a);
	if (min == 1)
		cmd_swap(stack_a->head, stack_a->tail, "sa\n");
	else if (min == 2)
	{
		cmd_rotate(stack_a->head, stack_a->tail, "ra\n");
		cmd_swap(stack_a->head, stack_a->tail, "sa\n");
	}
	else if (min == 3)
		cmd_reverse_rotate(stack_a->head, stack_a->tail, "rra\n");
	if (!check_already_sort(stack_a, 0))
	{
		cmd_push(stack_a->head, stack_b->head, stack_a->tail, "pb\n");
		sort_three(stack_a);
		cmd_push(stack_b->head, stack_a->head, stack_b->tail, "pa\n");
	}
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	min;

	min = get_min_index(stack_a);
	if (min == 1)
		cmd_swap(stack_a->head, stack_a->tail, "sa\n");
	else if (min == 2)
	{
		cmd_rotate(stack_a->head, stack_a->tail, "ra\n");
		cmd_swap(stack_a->head, stack_a->tail, "sa\n");
	}
	else if (min == 3)
	{
		cmd_reverse_rotate(stack_a->head, stack_a->tail, "rra\n");
		cmd_reverse_rotate(stack_a->head, stack_a->tail, "rra\n");
	}
	else if (min == 4)
		cmd_reverse_rotate(stack_a->head, stack_a->tail, "rra\n");
	if (!check_already_sort(stack_a, 0))
	{
		cmd_push(stack_a->head, stack_b->head, stack_a->tail, "pb\n");
		sort_four(stack_a, stack_b);
		cmd_push(stack_b->head, stack_a->head, stack_b->tail, "pa\n");
	}
}
