/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 11:15:29 by avallini          #+#    #+#             */
/*   Updated: 2024/01/02 12:34:52 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	int	tmp_data;

	if (stack->size < 2)
		return ;
	tmp_data = stack->top->data;
	stack->top->data = stack->top->next->data;
	stack->top->next->data = tmp_data;
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack)
{
	int	tmp_data;

	if (stack->size < 2)
		return ;
	tmp_data = stack->top->data;
	stack->top->data = stack->top->next->data;
	stack->top->next->data = tmp_data;
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	int	tmp_data;

	if (stack_a->size < 2 && stack_b->size < 2)
		return ;
	if (stack_a->size >= 2)
	{
		tmp_data = stack_a->top->data;
		stack_a->top->data = stack_a->top->next->data;
		stack_a->top->next->data = tmp_data;
	}
	if (stack_b->size >= 2)
	{
		tmp_data = stack_b->top->data;
		stack_b->top->data = stack_b->top->next->data;
		stack_b->top->next->data = tmp_data;
	}
	write(1, "ss\n", 3);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;
	int		data;

	if (stack_b->size == 0)
		return ;
	data = stack_b->top->data;
	remove_node_front(stack_b);
	node = new_node(data);
	add_node_front(node, stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;
	int		data;

	if (stack_a->size == 0)
		return ;
	data = stack_a->top->data;
	remove_node_front(stack_a);
	node = new_node(data);
	add_node_front(node, stack_b);
	write(1, "pb\n", 3);
}
