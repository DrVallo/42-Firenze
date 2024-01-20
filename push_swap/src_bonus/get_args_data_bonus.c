/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args_data_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 11:46:38 by avallini          #+#    #+#             */
/*   Updated: 2024/01/13 12:54:37 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	get_args_data(char *argv[], t_stack *stack)
{
	int		i;

	i = 0;
	while (argv[++i])
	{
		if (is_valid_data(argv[i]))
		{
			if (contain_space(argv[i]))
			{
				if (!split_string_number(argv[i], stack))
					return (0);
			}
			else if (argv[i][0])
			{
				if (!create_and_add_new_node(argv[i], stack, 0))
					return (0);
			}
		}
		else
			return (0);
	}
	return (1);
}

int	str_on_stack(char *str, int start, t_stack *stack)
{
	char	*nbr;
	int		end;
	int		i;

	end = start - 1;
	i = 0;
	while (str[++end])
	{
		if (!(str[end] >= 33 && str[end] <= 126))
			break ;
	}
	nbr = (char *)malloc(sizeof(char) * (end - start + 1));
	while (start < end)
	{
		nbr[i] = str[start];
		start++;
		i++;
	}
	nbr[i] = '\0';
	if (!create_and_add_new_node(nbr, stack, 1))
		return (0);
	return (1);
}

int	split_string_number(char *str, t_stack *stack)
{
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if ((str[i] >= 33 && str[i] <= 126) && !flag)
		{
			flag = 1;
			if (!str_on_stack(str, i, stack))
				return (0);
		}
		else if (str[i] == ' ' && flag)
			flag = 0;
		i++;
	}
	return (1);
}

int	create_and_add_new_node(char *nbr, t_stack *stack, int is_alloc)
{
	t_node	*node;

	node = NULL;
	if (ft_atoi(nbr) > INT_MAX || ft_atoi(nbr) < INT_MIN)
	{
		if (is_alloc)
			free(nbr);
		return (0);
	}
	node = new_node((int)ft_atoi(nbr));
	add_node_back(node, stack);
	if (is_alloc)
		free(nbr);
	return (1);
}
