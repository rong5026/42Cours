/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:35:33 by yeohong           #+#    #+#             */
/*   Updated: 2023/07/21 13:35:33 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_stack *stack_a)
{
	t_node	*node_i;
	t_node	*node_j;

	node_i = stack_a->head->next;
	while (node_i != stack_a->tail)
	{
		node_j = stack_a->head->next;
		node_i->index = 0;
		while (node_j != stack_a->tail)
		{
			if (node_i->elem > node_j->elem)
				node_i->index++;
			node_j = node_j->next;
		}
		node_i = node_i->next;
	}
}
