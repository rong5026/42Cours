/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:34:31 by yeohong           #+#    #+#             */
/*   Updated: 2023/07/21 13:34:32 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_stack *stack_a, t_stack *stack_b)
{
	set_index(stack_a);
	if (check_already_sort(stack_a, stack_b))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return ;
	}
	if (stack_size(stack_a) < 6)
	{
		if (stack_a->size == 2)
			sort_two(stack_a);
		else if (stack_a->size == 3)
			sort_three(stack_a);
		else if (stack_a->size == 4)
			sort_four(stack_a, stack_b);
		else if (stack_a->size == 5)
			sort_five(stack_a, stack_b);
	}
	else
		sorting_greedy(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
}
