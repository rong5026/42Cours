/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_sort_utils_compare.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:45:14 by yeohong           #+#    #+#             */
/*   Updated: 2023/07/21 13:35:46 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	runing_same_rotate(t_stack *a, t_stack *b, t_rotate *r)
{
	if (r->a * r->b > 0)
	{
		while (r->a > 0)
		{
			cmd_rr(a, b, "rr\n");
			r->a -= 1;
			r->b -= 1;
		}
		while (r->a < 0)
		{
			cmd_rrr(a, b, "rrr\n");
			r->a += 1;
			r->b += 1;
		}
	}
}

void	runing_a_b_rotate(t_stack *stack_a, t_stack *stack_b, t_rotate *rotate)
{
	a_rotate(stack_a, rotate->a);
	b_rotate(stack_b, rotate->b);
}

void	a_rotate(t_stack *stack_a, int n)
{
	int	i;

	i = 0;
	if (n > 0)
	{
		while (i < n)
		{
			cmd_rotate(stack_a->head, stack_a->tail, "ra\n");
			i++;
		}
	}
	else
	{
		n = abs(n);
		while (i < n)
		{
			cmd_reverse_rotate(stack_a->head, stack_a->tail, "rra\n");
			i++;
		}
	}
}

void	b_rotate(t_stack *stack_b, int n)
{
	int	i;

	i = 0;
	if (n > 0)
	{
		while (i < n)
		{
			cmd_rotate(stack_b->head, stack_b->tail, "rb\n");
			i++;
		}
	}
	else
	{
		n = abs(n);
		while (i < n)
		{
			cmd_reverse_rotate(stack_b->head, stack_b->tail, "rrb\n");
			i++;
		}
	}
}
