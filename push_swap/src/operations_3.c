/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 17:23:21 by avallini          #+#    #+#             */
/*   Updated: 2024/01/01 21:36:44 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*tmp_node;

	if (stack_a->size < 2 && stack_b->size < 2)
		return ;
	if (stack_a->size > 1)
	{
		tmp_node = stack_a->bottom;
		stack_a->bottom = tmp_node->prev;
		stack_a->bottom->next = NULL;
		tmp_node->next = stack_a->top;
		tmp_node->prev = NULL;
		stack_a->top->prev = tmp_node;
		stack_a->top = tmp_node;
	}
	if (stack_b->size > 1)
	{
		tmp_node = stack_b->bottom;
		stack_b->bottom = tmp_node->prev;
		stack_b->bottom->next = NULL;
		tmp_node->next = stack_b->top;
		tmp_node->prev = NULL;
		stack_b->top->prev = tmp_node;
		stack_b->top = tmp_node;
	}
	write(1, "rrr\n", 4);
}
