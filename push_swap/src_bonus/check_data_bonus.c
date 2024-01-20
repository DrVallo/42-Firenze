/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 11:04:12 by avallini          #+#    #+#             */
/*   Updated: 2024/01/13 12:54:40 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_sorted(t_stack *stack, int count)
{
	t_node	*node;

	node = stack->top;
	if (!node || !node->next || count <= 1)
		return (1);
	while (--count > 0)
	{
		if (!node->next)
			return (1);
		if (node->data < node->next->data)
			node = node->next;
		else
			return (0);
	}
	return (1);
}

int	is_sorted_b(t_stack *stack_a, t_stack *stack_b, int count)
{
	t_node	*node;
	int		i;

	i = count;
	node = stack_b->top;
	while (--count > 0)
	{
		if (node->data > node->next->data)
			node = node->next;
		else
			return (0);
	}
	while (i-- > 0)
		pa(stack_a, stack_b);
	return (1);
}

int	check_overlap(t_stack *stack)
{
	int		node_data;
	t_node	*main_node;
	t_node	*sub_node;

	main_node = stack->top;
	while (main_node)
	{
		node_data = main_node->data;
		sub_node = main_node->next;
		while (sub_node)
		{
			if (sub_node->data == node_data)
				return (1);
			sub_node = sub_node->next;
		}
		main_node = main_node->next;
	}
	return (0);
}

int	is_valid_data(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || (str[i] == '+'
				|| str[i] == '-') || str[i] == ' ')
		{
			if ((str[i] == '+' || str[i] == '-') && (!str[i + 1]
					|| !(str[i + 1] >= '0' && str[i + 1] <= '9')))
				return (0);
			if ((str[i] >= '0' && str[i] <= '9') && (str[i + 1]
					&& !(str[i] >= '0' && str[i] <= '9')
					&& str[i + 1] != ' '))
				return (0);
		}
		else
			return (0);
	}
	return (1);
}

int	contain_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}
