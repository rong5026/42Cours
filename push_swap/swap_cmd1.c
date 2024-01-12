/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_cmd1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:34:10 by yeohong           #+#    #+#             */
/*   Updated: 2023/07/21 13:34:22 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_ss(t_stack *stack_a, t_stack *stack_b, char *str)
{
	cmd_swap(stack_a->head, stack_a->tail, 0);
	cmd_swap(stack_b->head, stack_b->tail, 0);
	if (str)
		write(1, str, ft_strlen(str));
}

void	cmd_rr(t_stack *stack_a, t_stack *stack_b, char *str)
{
	cmd_rotate(stack_a->head, stack_a->tail, 0);
	cmd_rotate(stack_b->head, stack_b->tail, 0);
	if (str)
		write(1, str, ft_strlen(str));
}

void	cmd_rrr(t_stack *stack_a, t_stack *stack_b, char *str)
{
	cmd_reverse_rotate(stack_a->head, stack_a->tail, 0);
	cmd_reverse_rotate(stack_b->head, stack_b->tail, 0);
	if (str)
		write(1, str, ft_strlen(str));
}
