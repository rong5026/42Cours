/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 22:08:07 by yeohong           #+#    #+#             */
/*   Updated: 2023/07/21 13:35:49 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(t_stack *a, t_stack *b, char *str)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	write(1, str, ft_strlen(str));
	exit(0);
}

void	free_stack(t_stack *stack)
{
	t_node	*next;
	t_node	*tmp;

	tmp = stack->head;
	while (tmp != 0)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
}

void	free_split(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result[i]);
	free(result);
}
