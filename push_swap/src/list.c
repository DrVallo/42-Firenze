/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:30:07 by avallini          #+#    #+#             */
/*   Updated: 2024/01/02 12:31:51 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_node_back(t_node *node, t_stack *stack)
{
	if (!node || !stack)
		return ;
	if (!stack->top)
		stack->top = node;
	else
	{
		if (stack->bottom == stack->top)
		{
			node->prev = stack->top;
			stack->top->next = node;
		}
		else
		{
			node->prev = stack->bottom;
			stack->bottom->next = node;
		}
	}
	stack->bottom = node;
	stack->size++;
}

void	add_node_front(t_node *node, t_stack *stack)
{
	if (!node || !stack)
		return ;
	if (!stack->top)
		stack->bottom = node;
	else
	{
		if (stack->top == stack->bottom)
		{
			node->next = stack->top;
			stack->bottom->prev = node;
		}
		else
		{
			node->next = stack->top;
			stack->top->prev = node;
		}
	}
	stack->top = node;
	stack->size++;
}

void	remove_node_back(t_stack *stack)
{
	t_node	*node;

	if (!stack || stack->size <= 0)
		return ;
	if (stack->size == 1)
	{
		free(stack->bottom);
		stack->top = NULL;
		stack->bottom = NULL;
	}
	else
	{
		node = stack->bottom->prev;
		free(stack->bottom);
		stack->bottom = node;
		node->next = NULL;
	}
	stack->size--;
}

void	remove_node_front(t_stack *stack)
{
	t_node	*node;

	if (!stack || stack->size <= 0)
		return ;
	if (stack->size == 1)
	{
		free(stack->top);
		stack->top = NULL;
		stack->bottom = NULL;
	}
	else
	{
		node = stack->top->next;
		free(stack->top);
		stack->top = node;
		node->prev = NULL;
	}
	stack->size--;
}

t_node	*new_node(int data)
{
	t_node	*node;

	node = NULL;
	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->data = data;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

// Test function for print stack content
// void	print_stack(t_stack *stack)
// {
// 	t_node *node;

// 	if (!stack || stack->size == 0)
// 	{
// 		printf("Stack is empty.\n");
// 		return ;
// 	}
// 	printf("Top: %d[%p]\n", stack->top->data, stack->top);
// 	printf("Bottom: %d[%p]\n", stack->bottom->data, stack->bottom);
// 	node = stack->top;
// 	while (node)
// 	{
// 		printf("Node: %d[%p]", node->data, node);
// 		if (node->prev)
// 			printf("(Prev: %d)", node->prev->data);
// 		if (node->next)
// 			printf("(Next: %d)", node->next->data);
// 		printf("\n");
// 		node = node->next;
// 	}
// 	printf("STACK SIZE = %d.\n", stack->size);
// 	printf("-------------------\n");
// }
