/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:41:08 by avallini          #+#    #+#             */
/*   Updated: 2024/06/22 15:27:03 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (0);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ms_sleep(long time_to_sleep)
{
	usleep(time_to_sleep * 1000);
}

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	args_is_only_digit(char *argv[])
{
	int	i;
	int	k;

	i = 0;
	while (argv[++i])
	{
		k = -1;
		while (argv[i][++k])
		{
			if (!is_digit(argv[i][k]))
				return (0);
		}
	}
	return (1);
}

long	ft_atol(char *str)
{
	long	nb;
	long	prev_nb;
	int		i;

	nb = 0;
	prev_nb = 0;
	i = -1;
	while (str[++i])
	{
		prev_nb = nb;
		nb = nb * 10 + str[i] - '0';
		if (prev_nb > nb)
			return (-1);
	}
	return (nb);
}
