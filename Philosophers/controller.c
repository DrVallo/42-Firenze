/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:40:46 by avallini          #+#    #+#             */
/*   Updated: 2024/06/22 14:51:39 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_valid_routine(t_philo *philo)
{
	int	sim_end;

	pthread_mutex_lock(&philo->table->eat_lock);
	sim_end = philo->table->sim_end;
	pthread_mutex_unlock(&philo->table->eat_lock);
	if (sim_end)
		return (0);
	return (1);
}

int	check_philo_death_and_full(t_table *table)
{
	int	i;
	int	is_end;

	is_end = 0;
	i = -1;
	while (++i < table->nb_philosopers && !is_end)
	{
		pthread_mutex_lock(&table->print_lock);
		pthread_mutex_lock(&table->eat_lock);
		if (table->philos[i].eat_count != table->nb_must_eat
			&& get_time() - table->philos[i].last_eat >= table->time_to_die)
		{
			table->sim_end = 1;
			printf("%ld %d died\n", get_time() - table->start_time,
				table->philos[i].id);
		}
		if (table->full_philos == table->nb_philosopers
			|| table->nb_must_eat == 0)
			table->sim_end = 1;
		is_end = table->sim_end;
		pthread_mutex_unlock(&table->eat_lock);
		pthread_mutex_unlock(&table->print_lock);
	}
	return (is_end);
}

void	*controller_routine(void *data)
{
	t_table	*table;

	table = (t_table *)data;
	while (1)
	{
		if (check_philo_death_and_full(table))
			break ;
	}
	return (NULL);
}
