/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 21:26:34 by avallini          #+#    #+#             */
/*   Updated: 2024/01/13 12:55:55 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	init_stack(&stack_a, &stack_b);
	if (argc > 1)
	{
		if (!get_args_data(argv, stack_a) || check_overlap(stack_a))
			write(1, "Error\n", 6);
		else
		{
			if (!is_sorted(stack_a, stack_a->size))
			{
				a_to_b(stack_a, stack_b, stack_a->size);
			}
		}
	}
	free_stack(stack_a);
	free_stack(stack_b);
}

void	free_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*tmp_node;

	node = stack->top;
	tmp_node = NULL;
	while (node)
	{
		tmp_node = node->next;
		free(node);
		node = tmp_node;
	}
	free(stack);
}
