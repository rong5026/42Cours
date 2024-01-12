/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 17:06:55 by yeohong           #+#    #+#             */
/*   Updated: 2023/07/21 13:38:37 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				elem;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	struct s_node	*head;
	struct s_node	*tail;
	int				size;
}	t_stack;

typedef struct s_rotate
{
	int	a;
	int	b;
}	t_rotate;

// error.c
void	print_error(t_stack *a, t_stack *b, char *str);
void	free_stack(t_stack *stack);
void	free_split(char **result);

//greedy_sort_utils_compare.c
void	runing_same_rotate(t_stack *a, t_stack *b, t_rotate *r);
void	runing_a_b_rotate(t_stack *stack_a, t_stack *stack_b, t_rotate *rotate);
void	a_rotate(t_stack *stack_a, int n);
void	b_rotate(t_stack *stack_b, int n);

//greedy_sort_utils_index.c
int		get_stack_max_index(t_stack *stack);
int		get_stack_min_index(t_stack *stack);
int		find_max_position(t_stack *stack_a, int max_index);
int		find_min_position(t_stack *stack_a, int min_index);
int		find_mid_position(t_stack *stack_a, int b_index);

//greedy_sort_utils.c
void	get_min_a_b(t_stack *stack_a, t_stack *stack_b, t_rotate *rotate);
int		get_min_a_rotate(t_stack *stack_a, int index);
int		get_min_b_rotate(t_stack *stack_b, int index);
int		get_half_index(int size, int index);
void	compare_a_b(int a, int b, t_rotate *rotate);

//greedy_sort.c
void	sorting_greedy(t_stack *stack_a, t_stack *stack_b);
void	a_to_b(t_stack *stack_a, t_stack *stack_b, int pivot1, int pivot2);
void	b_to_a(t_stack *stack_a, t_stack *stack_b);
void	a_last_sorting(t_stack *stack_a, t_stack *stack_b);
void	set_rotate(int a, int b, t_rotate *rotate);

//indexing.c
void	set_index(t_stack *stack_a);

//check_input.c
int		check_number(char *str);
void	check_split(t_stack *stack_a, t_stack *stack_b, char **result);
int		check_integer(long num);
void	check_duplicate(t_stack *stack_a, t_stack *stack_b);
int		check_already_sort(t_stack *stack_a, t_stack *stack_b);

//node_set.c
int		init_set(t_stack *stack_a, t_stack *stack_b);
int		init_a_and_b_stack(t_stack *stack_a, t_stack *stack_b);
t_node	*init_node(int value);
t_node	*input_stack(t_stack *stack_a, t_stack *stack_b, int elem);

//parsing_input.c
int		parsing(int argc, char **argv, t_stack *stack_a, t_stack *stack_b);
int		is_space1(char ch);
int		check_plus_minus(char *str);

//origin_sort.c
void	sort_two(t_stack *stack_a);
void	sort_three(t_stack *stack_a);
void	sort_four(t_stack *stack_a, t_stack *stack_b);
void	sort_five(t_stack *stack_a, t_stack *stack_b);

//sorting.c
void	sorting(t_stack *stack_a, t_stack *stack_b);

//swap_cmd.c
void	cmd_swap(t_node *head_a, t_node *tail_a, char *str);
void	cmd_push(t_node *head_a, t_node *head_b, t_node *tail_a, char *str);
void	cmd_rotate(t_node *head_a, t_node *tail_a, char *str);
void	cmd_reverse_rotate(t_node *head_a, t_node *tail_a, char *str);

//swap_cmd1.c
void	cmd_ss(t_stack *stack_a, t_stack *stack_b, char *str);
void	cmd_rr(t_stack *stack_a, t_stack *stack_b, char *str);
void	cmd_rrr(t_stack *stack_a, t_stack *stack_b, char *str);

//utils.c
int		stack_size(t_stack *stack);
int		get_min_index(t_stack *stack_a);
int		get_top_index(t_stack *stack_a);
int		abs(int a);
int		min(int a, int b);

#endif
