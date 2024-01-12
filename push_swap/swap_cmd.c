/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:34:15 by yeohong           #+#    #+#             */
/*   Updated: 2023/07/21 13:34:19 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_swap(t_node *head_a, t_node *tail_a, char *str)
{
	t_node	*node_a1;
	t_node	*node_a2;
	int		tmp;

	node_a1 = head_a->next;
	if (node_a1 == tail_a)
		return ;
	node_a2 = node_a1->next;
	if (node_a2 == tail_a)
		return ;
	tmp = node_a1->elem;
	node_a1->elem = node_a2->elem;
	node_a2->elem = tmp;
	tmp = node_a1->index;
	node_a1->index = node_a2->index;
	node_a2->index = tmp;
	if (str)
		write(1, str, ft_strlen(str));
}

void	cmd_push(t_node *head_a, t_node *head_b, t_node *tail_a, char *str)
{
	t_node	*node;

	if (head_a->next == tail_a)
		return ;
	node = head_a->next;
	head_a->next = node->next;
	node->next->prev = head_a;
	node->next = head_b->next;
	node->prev = head_b;
	node->next->prev = node;
	head_b->next = node;
	if (str)
		write(1, str, ft_strlen(str));
}

void	cmd_rotate(t_node *head_a, t_node *tail_a, char *str)
{
	t_node	*node;

	if (head_a->next == tail_a
		|| head_a->next->next == tail_a)
		return ;
	node = head_a->next;
	head_a->next = node->next;
	node->next->prev = head_a;
	tail_a->prev->next = node;
	node->prev = tail_a->prev;
	node->next = tail_a;
	tail_a->prev = node;
	if (str)
		write(1, str, ft_strlen(str));
}

void	cmd_reverse_rotate(t_node *head_a, t_node *tail_a, char *str)
{
	t_node	*node;

	if (head_a->next == tail_a
		|| head_a->next->next == tail_a)
		return ;
	node = tail_a->prev;
	node->prev->next = tail_a;
	tail_a->prev = node->prev;
	head_a->next->prev = node;
	node->next = head_a->next;
	node->prev = head_a;
	head_a->next = node;
	if (str)
		write(1, str, ft_strlen(str));
}
