/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 17:01:55 by yeohong           #+#    #+#             */
/*   Updated: 2023/07/21 13:35:04 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		i;

	if (argc < 2)
		return (0);
	i = 1;
	while (argv[i])
	{
		if (!check_number(argv[i++]))
			print_error(0, 0, "Error\n");
	}
	if (!init_set(&stack_a, &stack_b))
		print_error(&stack_a, &stack_b, "Error\n");
	parsing(argc, argv, &stack_a, &stack_b);
	check_duplicate(&stack_a, &stack_b);
	sorting(&stack_a, &stack_b);
	return (0);
}
