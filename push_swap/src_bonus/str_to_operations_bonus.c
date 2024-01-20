/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_operations_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:38:46 by avallini          #+#    #+#             */
/*   Updated: 2024/01/13 12:57:08 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	compare_str(char *s1, char *s2, int n)
{
	while (n >= 0)
	{
		if (s1[n] != s2[n])
			return (0);
		n--;
	}
	return (1);
}

void	str_to_operations(char *str, t_stack *stack_a, t_stack *stack_b)
{
	if (compare_str(str, "sa", str_len(str)))
		sa(stack_a);
	else if (compare_str(str, "sb", str_len(str)))
		sb(stack_b);
	else if (compare_str(str, "ss", str_len(str)))
		ss(stack_a, stack_b);
	else if (compare_str(str, "pa", str_len(str)))
		pa(stack_a, stack_b);
	else if (compare_str(str, "pb", str_len(str)))
		pb(stack_a, stack_b);
	else if (compare_str(str, "ra", str_len(str)))
		ra(stack_a);
	else if (compare_str(str, "rb", str_len(str)))
		rb(stack_b);
	else if (compare_str(str, "rr", str_len(str)))
		rr(stack_a, stack_b);
	else if (compare_str(str, "rra", str_len(str)))
		rra(stack_a);
	else if (compare_str(str, "rrb", str_len(str)))
		rrb(stack_b);
	else if (compare_str(str, "rrr", str_len(str)))
		rrr(stack_a, stack_b);
	else
		error_exit(stack_a, stack_b, str);
}
