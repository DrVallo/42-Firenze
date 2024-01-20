/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 10:20:37 by avallini          #+#    #+#             */
/*   Updated: 2024/01/02 12:32:26 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(t_stack *stack_a, t_stack *stack_b, int count)
{
	t_opr	*opr;

	if (is_sorted(stack_a, count))
		return ;
	if (quick_sort_a(stack_a, stack_b, count))
		return ;
	opr = init_opr(count);
	sort_a(stack_a, stack_b, opr, count);
	rotate_back(stack_a, stack_b, opr);
	a_to_b(stack_a, stack_b, opr->ra_count);
	b_to_a(stack_a, stack_b, opr->rb_count);
	b_to_a(stack_a, stack_b, opr->pb_count - opr->rb_count);
	free(opr);
}

int	quick_sort_a(t_stack *stack_a, t_stack *stack_b, int count)
{
	if (count == 2)
	{
		if (!is_sorted(stack_a, count))
			sa(stack_a);
		return (1);
	}
	else if (count == 3)
	{
		three_sort(stack_a);
		return (1);
	}
	else if (count == 5)
	{
		first_five_sort(stack_a, stack_b);
		return (1);
	}
	return (0);
}

void	sort_a(t_stack *stack_a, t_stack *stack_b, t_opr *opr, int count)
{
	int	i;

	i = -1;
	opr->pivot_b = ((get_lower_data(stack_a, count)
				+ get_higher_data(stack_a, count)) / 2);
	opr->pivot_s = ((get_lower_data(stack_a, count) + opr->pivot_b) / 2);
	while (++i < count)
	{
		if (stack_a->top->data > opr->pivot_b)
		{
			ra(stack_a);
			opr->ra_count++;
		}
		else
		{
			pb(stack_a, stack_b);
			opr->pb_count++;
			if (stack_b->top->data > opr->pivot_s)
			{
				rb(stack_b);
				opr->rb_count++;
			}
		}
	}
}

void	rotate_back(t_stack *stack_a, t_stack *stack_b, t_opr *opr)
{
	int	i;

	i = -1;
	if (opr->ra_count > opr->rb_count)
	{
		while (++i < opr->rb_count)
			rrr(stack_a, stack_b);
		while (++i <= opr->ra_count && opr->rb_count == stack_b->size)
			rra(stack_a);
		while (i++ <= opr->ra_count && opr->origin_size < stack_a->size)
			rra(stack_a);
	}
	else
	{
		while (++i < opr->ra_count)
			rrr(stack_a, stack_b);
		while (++i <= opr->rb_count && opr->ra_count == stack_a->size)
			rrb(stack_b);
		while (i++ <= opr->rb_count && opr->origin_size < stack_b->size)
			rrb(stack_b);
	}
}
