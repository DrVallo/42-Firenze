/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 21:26:34 by avallini          #+#    #+#             */
/*   Updated: 2024/01/13 12:57:38 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*str;

	init_stack(&stack_a, &stack_b);
	str = NULL;
	if (argc > 1)
	{
		if (!get_args_data(argv, stack_a) || check_overlap(stack_a))
			error_exit(stack_a, stack_b, str);
		while (1)
		{
			str = get_terminal_input();
			if (!str)
				break ;
			str_to_operations(str, stack_a, stack_b);
			free(str);
		}
		if (is_sorted(stack_a, stack_a->size))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	free_stack(stack_a);
	free_stack(stack_b);
}

void	error_exit(t_stack *stack_a, t_stack *stack_b, char *str)
{
	if (str)
		free(str);
	free_stack(stack_a);
	free_stack(stack_b);
	write(1, "Error\n", 6);
	exit(1);
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
