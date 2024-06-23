/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:40:49 by avallini          #+#    #+#             */
/*   Updated: 2024/06/08 14:56:30 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philos(t_table *table)
{
	int	i;

	table->philos = malloc(sizeof(t_philo) * table->nb_philosopers);
	if (!table->philos)
		return (0);
	i = -1;
	while (++i < table->nb_philosopers)
	{
		table->philos[i].id = i + 1;
		table->philos[i].forks[0] = table->philos[i].id - 1;
		table->philos[i].forks[1] = (table->philos[i].id)
			% table->nb_philosopers;
		if (table->philos[i].id - 1 % 2)
		{
			table->philos[i].forks[0] = (table->philos[i].id)
				% table->nb_philosopers;
			table->philos[i].forks[1] = table->philos[i].id - 1;
		}
		table->philos[i].last_eat = 0;
		table->philos[i].eat_count = 0;
		table->philos[i].table = table;
	}
	return (1);
}

int	init_threads(t_table *table)
{
	int	i;

	i = -1;
	table->start_time = get_time();
	while (++i < table->nb_philosopers)
	{
		table->philos[i].last_eat = table->start_time;
		if (pthread_create(&table->philos[i].thread, NULL,
				philo_routine, &table->philos[i]) != 0)
			return (0);
	}
	if (pthread_create(&table->controller, NULL,
			controller_routine, (void *)table) != 0)
		return (0);
	i = -1;
	while (++i < table->nb_philosopers)
	{
		if (pthread_join(table->philos[i].thread, NULL) != 0)
			return (0);
	}
	if (pthread_join(table->controller, NULL) != 0)
		return (0);
	return (1);
}

int	init_forks(t_table *table)
{
	int	i;

	table->forks = malloc(sizeof(pthread_mutex_t) * table->nb_philosopers);
	if (!table->forks)
		return (0);
	i = -1;
	while (++i < table->nb_philosopers)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
			return (0);
	}
	if (pthread_mutex_init(&table->print_lock, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&table->eat_lock, NULL) != 0)
		return (0);
	return (1);
}
