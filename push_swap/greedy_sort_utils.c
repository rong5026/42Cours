/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:54:25 by yeohong           #+#    #+#             */
/*   Updated: 2023/07/21 13:35:40 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_min_a_b(t_stack *stack_a, t_stack *stack_b, t_rotate *rotate)
{
	int		i;
	t_node	*node;
	int		a;
	int		b;
	int		size_b;

	size_b = stack_size(stack_b);
	node = stack_b->head->next;
	i = 0;
	while (i < size_b)
	{
		a = get_min_a_rotate(stack_a, node->index);
		b = get_min_b_rotate(stack_b, i);
		if (i == 0)
			set_rotate(a, b, rotate);
		else
			compare_a_b(a, b, rotate);
		i++;
		node = node->next;
	}
}

int	get_min_a_rotate(t_stack *stack_a, int index)
{
	int	result;
	int	max;
	int	min;

	max = get_stack_max_index(stack_a);
	min = get_stack_min_index(stack_a);
	if (index > max)
		result = find_max_position(stack_a, max);
	else if (index < min)
		result = find_min_position(stack_a, min);
	else
		result = find_mid_position(stack_a, index);
	return (result);
}

int	get_min_b_rotate(t_stack *stack_b, int index)
{
	return (get_half_index(stack_size(stack_b), index));
}

int	get_half_index(int size, int index)
{
	if (index >= (size + 1) / 2)
		return (-(size - index));
	else
		return (index);
}

void	compare_a_b(int a, int b, t_rotate *rotate)
{
	if (abs(a) + abs(b) < abs(rotate->a) + abs(rotate->b))
		set_rotate(a, b, rotate);
}
