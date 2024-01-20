/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 21:15:41 by avallini          #+#    #+#             */
/*   Updated: 2024/01/13 13:54:31 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*top;
	t_node	*bottom;
}	t_stack;

typedef struct s_opr
{
	int	ra_count;
	int	rb_count;
	int	pa_count;
	int	pb_count;
	int	origin_size;
	int	pivot_b;
	int	pivot_s;
}	t_opr;

// src_bonus/get_terminal_input.c
char		*get_terminal_input(void);
int			str_len(char *str);

// src_bonus/str_to_operations.c
void		str_to_operations(char *str, t_stack *stack_a, t_stack *stack_b);

// src_bonus/main.c
void		error_exit(t_stack *stack_a, t_stack *stack_b, char *str);
void		free_stack(t_stack *stack);

// src_bonus/check_data.c
int			is_sorted(t_stack *stack, int count);
int			is_sorted_b(t_stack *stack_a, t_stack *stack_b, int count);
int			check_overlap(t_stack *stack);
int			is_valid_data(char *str);
int			contain_space(char *str);

// src_bonus/get_args_data.c
int			get_args_data(char *argv[], t_stack *stack);
int			str_on_stack(char *str, int start, t_stack *stack);
int			split_string_number(char *str, t_stack *stack);
int			create_and_add_new_node(char *nbr, t_stack *stack, int is_alloc);

// src_bonus/init_data.c
void		init_stack(t_stack **stack_a, t_stack **stack_b);
t_opr		*init_opr(int size);

// src_bonus/list.c
void		add_node_back(t_node *node, t_stack *stack);
void		add_node_front(t_node *node, t_stack *stack);
void		remove_node_back(t_stack *stack);
void		remove_node_front(t_stack *stack);
t_node		*new_node(int data);

// src_bonus/operations.c
void		sa(t_stack *stack);
void		sb(t_stack *stack);
void		ss(t_stack *stack_a, t_stack *stack_b);
void		pa(t_stack *stack_a, t_stack *stack_b);
void		pb(t_stack *stack_a, t_stack *stack_b);

// src_bonus/operations_2.c
void		ra(t_stack *stack);
void		rb(t_stack *stack);
void		rr(t_stack *stack_a, t_stack *stack_b);
void		rra(t_stack *stack);
void		rrb(t_stack *stack);

// src_bonus/operations_4.c
void		rrr(t_stack *stack_a, t_stack *stack_b);

// src_bonus/quick_sort.c
void		three_sort(t_stack *stack);
void		first_three_sort(t_stack *stack);
void		first_five_sort(t_stack *stack_a, t_stack *stack_b);

// src_bonus/sort_a.c
void		a_to_b(t_stack *stack_a, t_stack *stack_b, int count);
int			quick_sort_a(t_stack *stack_a, t_stack *stack_b, int count);
void		sort_a(t_stack *stack_a, t_stack *stack_b, t_opr *opr, int count);
void		rotate_back(t_stack *stack_a, t_stack *stack_b, t_opr *opr);

// src_bonus/sort_b.c
void		b_to_a(t_stack *stack_a, t_stack *stack_b, int count);
void		two_sort_b(t_stack *stack_a, t_stack *stack_b);
int			quick_sort_b(t_stack *stack_a, t_stack *stack_b, int count);
void		sort_b(t_stack *stack_a, t_stack *stack_b, t_opr *opr, int count);

// src_bonus/utils.c
long long	ft_atoi(const char *nptr);
int			get_lower_data(t_stack *stack, int count);
int			get_higher_data(t_stack *stack, int count);
int			get_middle_data(t_stack *stack, int size);
void		arr_sort(int *arr, int size);

// Test function in src_bonus/list.c
// void	print_stack(t_stack *stack);

#endif
