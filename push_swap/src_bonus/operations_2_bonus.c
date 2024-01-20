/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 16:50:40 by avallini          #+#    #+#             */
/*   Updated: 2024/01/13 13:44:48 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra(t_stack *stack)
{
	t_node	*tmp_node;

	if (stack->size < 2)
		return ;
	tmp_node = stack->top;
	stack->top = tmp_node->next;
	stack->top->prev = NULL;
	tmp_node->prev = stack->bottom;
	tmp_node->next = NULL;
	stack->bottom->next = tmp_node;
	stack->bottom = tmp_node;
}

void	rb(t_stack *stack)
{
	t_node	*tmp_node;

	if (stack->size < 2)
		return ;
	tmp_node = stack->top;
	stack->top = tmp_node->next;
	stack->top->prev = NULL;
	tmp_node->prev = stack->bottom;
	tmp_node->next = NULL;
	stack->bottom->next = tmp_node;
	stack->bottom = tmp_node;
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*tmp_node;

	if (stack_a->size < 2 && stack_b->size < 2)
		return ;
	if (stack_a->size > 1)
	{
		tmp_node = stack_a->top;
		stack_a->top = tmp_node->next;
		stack_a->top->prev = NULL;
		tmp_node->prev = stack_a->bottom;
		tmp_node->next = NULL;
		stack_a->bottom->next = tmp_node;
		stack_a->bottom = tmp_node;
	}
	if (stack_b->size > 1)
	{
		tmp_node = stack_b->top;
		stack_b->top = tmp_node->next;
		stack_b->top->prev = NULL;
		tmp_node->prev = stack_b->bottom;
		tmp_node->next = NULL;
		stack_b->bottom->next = tmp_node;
		stack_b->bottom = tmp_node;
	}
}

void	rra(t_stack *stack)
{
	t_node	*tmp_node;

	if (stack->size < 2)
		return ;
	tmp_node = stack->bottom;
	stack->bottom = tmp_node->prev;
	stack->bottom->next = NULL;
	tmp_node->next = stack->top;
	tmp_node->prev = NULL;
	stack->top->prev = tmp_node;
	stack->top = tmp_node;
}

void	rrb(t_stack *stack)
{
	t_node	*tmp_node;

	if (stack->size < 2)
		return ;
	tmp_node = stack->bottom;
	stack->bottom = tmp_node->prev;
	stack->bottom->next = NULL;
	tmp_node->next = stack->top;
	tmp_node->prev = NULL;
	stack->top->prev = tmp_node;
	stack->top = tmp_node;
}
