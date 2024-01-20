/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 13:36:28 by avallini          #+#    #+#             */
/*   Updated: 2024/01/13 12:54:15 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	b_to_a(t_stack *stack_a, t_stack *stack_b, int count)
{
	t_opr	*opr;

	if (quick_sort_b(stack_a, stack_b, count))
		return ;
	opr = init_opr(count);
	sort_b(stack_a, stack_b, opr, count);
	a_to_b(stack_a, stack_b, opr->pa_count - opr->ra_count);
	rotate_back(stack_a, stack_b, opr);
	a_to_b(stack_a, stack_b, opr->ra_count);
	b_to_a(stack_a, stack_b, opr->rb_count);
	free(opr);
}

void	two_sort_b(t_stack *stack_a, t_stack *stack_b)
{
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	if (stack_a->top->data > stack_a->top->next->data)
		sa(stack_a);
}

int	quick_sort_b(t_stack *stack_a, t_stack *stack_b, int count)
{
	if (count == 0)
		return (1);
	if (count == 1)
	{
		pa(stack_a, stack_b);
		return (1);
	}
	else if (count == 2)
	{
		two_sort_b(stack_a, stack_b);
		return (1);
	}
	if (is_sorted_b(stack_a, stack_b, count))
		return (1);
	return (0);
}

void	sort_b(t_stack *stack_a, t_stack *stack_b, t_opr *opr, int count)
{
	int	i;

	i = -1;
	opr->pivot_b = ((get_lower_data(stack_b, count)
				+ get_higher_data(stack_b, count)) / 2);
	opr->pivot_s = ((get_lower_data(stack_b, count) + opr->pivot_b) / 2);
	while (++i < count)
	{
		if (stack_b->top->data <= opr->pivot_s)
		{
			rb(stack_b);
			opr->rb_count++;
		}
		else
		{
			pa(stack_a, stack_b);
			opr->pa_count++;
			if (stack_a->top->data <= opr->pivot_b)
			{
				ra(stack_a);
				opr->ra_count++;
			}
		}
	}
}
