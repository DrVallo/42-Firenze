/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 21:53:09 by avallini          #+#    #+#             */
/*   Updated: 2024/01/13 12:56:44 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoi(const char *nptr)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10;
		result = result + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

int	get_lower_data(t_stack *stack, int count)
{
	t_node	*node;
	int		lower;

	node = stack->top;
	lower = node->data;
	while (--count > 0)
	{
		if (lower > node->next->data)
			lower = node->next->data;
		node = node->next;
	}
	return (lower);
}

int	get_higher_data(t_stack *stack, int count)
{
	t_node	*node;
	int		higher;

	node = stack->top;
	higher = node->data;
	while (--count > 0)
	{
		if (higher < node->next->data)
			higher = node->next->data;
		node = node->next;
	}
	return (higher);
}

int	get_middle_data(t_stack *stack, int size)
{
	t_node	*node;
	int		*arr;
	int		i;
	int		middle;

	node = stack->top;
	i = 0;
	arr = (int *)malloc(sizeof(int) * stack->size);
	while (node && i < size)
	{
		arr[i] = node->data;
		node = node->next;
		i++;
	}
	arr_sort(arr, size);
	middle = arr[size / 2];
	free(arr);
	return (middle);
}

void	arr_sort(int *arr, int size)
{
	int	i;
	int	k;
	int	current;

	i = 1;
	while (i < size)
	{
		current = arr[i];
		k = i - 1;
		while (k >= 0 && arr[k] > current)
		{
			arr[k + 1] = arr[k];
			k--;
		}
		arr[k + 1] = current;
		i++;
	}
}
