/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:33:36 by yeohong           #+#    #+#             */
/*   Updated: 2023/07/21 13:39:51 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_greedy(t_stack *stack_a, t_stack *stack_b)
{
	int	pivot1;
	int	pivot2;
	int	result;

	pivot1 = stack_size(stack_a) / 3;
	pivot2 = stack_size(stack_a) / 3 * 2;
	a_to_b(stack_a, stack_b, pivot1, pivot2);
	a_last_sorting(stack_a, stack_b);
	b_to_a(stack_a, stack_b);
	result = find_min_position(stack_a, get_stack_min_index(stack_a));
	a_rotate(stack_a, result);
}

void	a_to_b(t_stack *stack_a, t_stack *stack_b, int pivot1, int pivot2)
{
	int		i;
	int		size;

	i = 1;
	size = stack_size(stack_a);
	while (i < size)
	{
		if (get_top_index(stack_a) >= pivot2)
			cmd_rotate(stack_a->head, stack_a->tail, "ra\n");
		else if (get_top_index(stack_a) >= pivot1)
			cmd_push(stack_a->head, stack_b->head, stack_a->tail, "pb\n");
		else
		{
			cmd_push(stack_a->head, stack_b->head, stack_a->tail, "pb\n");
			cmd_rotate(stack_b->head, stack_b->tail, "rb\n");
		}
		i++;
	}
	i = stack_size(stack_a) + 1;
	{
		while (--i > 5)
			cmd_push(stack_a->head, stack_b->head, stack_a->tail, "pb\n");
	}
}

void	b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	t_rotate	rotate;

	rotate.a = 0;
	rotate.b = 0;
	while (stack_size(stack_b) > 0)
	{
		get_min_a_b(stack_a, stack_b, &rotate);
		runing_same_rotate(stack_a, stack_b, &rotate);
		runing_a_b_rotate(stack_a, stack_b, &rotate);
		cmd_push(stack_b->head, stack_a->head, stack_b->tail, "pa\n");
	}
}

void	a_last_sorting(t_stack *stack_a, t_stack *stack_b)
{
	int	size;

	size = stack_size(stack_a);
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
}

void	set_rotate(int a, int b, t_rotate *rotate)
{
	rotate->a = a;
	rotate->b = b;
}
