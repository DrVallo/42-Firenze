/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:40:43 by avallini          #+#    #+#             */
/*   Updated: 2024/06/22 14:49:42 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_forks(t_philo *philo)
{
	if (philo->table->nb_philosopers == 1)
	{
		pthread_mutex_lock(&philo->table->forks[philo->forks[0]]);
		print_message("has taken a fork", philo);
		ms_sleep(philo->table->time_to_die);
		pthread_mutex_unlock(&philo->table->forks[philo->forks[0]]);
		return (0);
	}
	if (philo->table->nb_philosopers % 2
		&& philo->id == philo->table->nb_philosopers - 1 % 2)
		ms_sleep(1);
	pthread_mutex_lock(&philo->table->forks[philo->forks[0]]);
	print_message("has taken a fork", philo);
	pthread_mutex_lock(&philo->table->forks[philo->forks[1]]);
	print_message("has taken a fork", philo);
	return (1);
}

void	philo_eat(t_philo *philo)
{
	print_message("is eating", philo);
	pthread_mutex_lock(&philo->table->eat_lock);
	philo->last_eat = get_time();
	if (philo->eat_count < philo->table->nb_must_eat)
		philo->eat_count++;
	if (philo->eat_count == philo->table->nb_must_eat)
		philo->table->full_philos++;
	pthread_mutex_unlock(&philo->table->eat_lock);
	ms_sleep(philo->table->time_to_eat);
	pthread_mutex_unlock(&philo->table->forks[philo->forks[0]]);
	pthread_mutex_unlock(&philo->table->forks[philo->forks[1]]);
}

void	*philo_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->id % 2)
		ms_sleep(philo->table->time_to_eat);
	while (is_valid_routine(philo) && philo->table->nb_must_eat != 0)
	{
		if (!get_forks(philo))
			break ;
		philo_eat(philo);
		if (philo->eat_count == philo->table->nb_must_eat)
			break ;
		print_message("is sleeping", philo);
		ms_sleep(philo->table->time_to_sleep);
		print_message("is thinking", philo);
	}
	return (NULL);
}
