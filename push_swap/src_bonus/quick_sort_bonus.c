/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 11:04:53 by avallini          #+#    #+#             */
/*   Updated: 2024/01/13 12:54:20 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	three_sort(t_stack *stack)
{
	if (stack->size == 3)
	{
		if (!is_sorted(stack, stack->size))
		{
			if (stack->top->next->data > stack->top->data
				&& stack->top->next->data > stack->bottom->data)
				rra(stack);
			else if (stack->top->data > stack->top->next->data
				&& stack->top->data > stack->bottom->data)
				ra(stack);
			if (stack->top->data > stack->top->next->data)
				sa(stack);
		}
	}
	else
		first_three_sort(stack);
}

void	first_three_sort(t_stack *stack)
{
	if (stack->top->data < stack->top->next->data)
	{
		if (stack->top->next->data < stack->top->next->next->data)
			return ;
		ra(stack);
		sa(stack);
		rra(stack);
	}
	else if (stack->top->data > stack->top->next->next->data)
	{
		sa(stack);
		ra(stack);
		sa(stack);
		rra(stack);
	}
	if (stack->top->data > stack->top->next->data)
		sa(stack);
}

void	first_five_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_opr	*opr;
	int		pivot;

	opr = init_opr(5);
	pivot = get_middle_data(stack_a, 5);
	while (1)
	{
		if (stack_a->top->data < pivot)
		{
			pb(stack_a, stack_b);
			opr->pb_count++;
		}
		else
		{
			ra(stack_a);
			opr->ra_count++;
		}
		if (opr->pb_count == 2)
			break ;
	}
	while (opr->ra_count-- && stack_a->size != 3)
		rra(stack_a);
	three_sort(stack_a);
	two_sort_b(stack_a, stack_b);
	free(opr);
}
