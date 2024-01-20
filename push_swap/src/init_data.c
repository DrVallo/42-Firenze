/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 21:27:14 by avallini          #+#    #+#             */
/*   Updated: 2024/01/13 12:49:52 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = (t_stack *)malloc(sizeof(t_stack));
	if (!*stack_a)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	(*stack_a)->size = 0;
	(*stack_a)->top = NULL;
	(*stack_a)->bottom = NULL;
	*stack_b = (t_stack *)malloc(sizeof(t_stack));
	if (!*stack_b)
	{
		write(1, "Error\n", 6);
		free(stack_a);
		exit(1);
	}
	(*stack_b)->size = 0;
	(*stack_b)->top = NULL;
	(*stack_b)->bottom = NULL;
}

t_opr	*init_opr(int size)
{
	t_opr	*opr;

	opr = (t_opr *)malloc(sizeof(t_opr));
	if (!opr)
	{
		write(1, "Error\n", 6);
		return (NULL);
	}
	opr->ra_count = 0;
	opr->rb_count = 0;
	opr->pa_count = 0;
	opr->pb_count = 0;
	opr->origin_size = size;
	opr->pivot_b = 0;
	opr->pivot_s = 0;
	return (opr);
}
