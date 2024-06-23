/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:40:39 by avallini          #+#    #+#             */
/*   Updated: 2024/06/22 15:35:29 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean_data(t_table *table)
{
	int	i;

	if (table->forks)
	{
		i = -1;
		while (++i < table->nb_philosopers)
			pthread_mutex_destroy(&table->forks[i]);
		pthread_mutex_destroy(&table->eat_lock);
		pthread_mutex_destroy(&table->print_lock);
		free(table->forks);
	}
	if (table->philos)
		free(table->philos);
}

void	error_exit(char *error, t_table *table)
{
	printf("%s\n", error);
	clean_data(table);
	exit(1);
}

void	print_message(char *str, t_philo *philo)
{
	long	cur_time;

	pthread_mutex_lock(&philo->table->print_lock);
	if (is_valid_routine(philo))
	{
		cur_time = get_time() - philo->table->start_time;
		printf("%ld %d %s\n", cur_time, philo->id, str);
	}
	pthread_mutex_unlock(&philo->table->print_lock);
}

int	get_args(t_table *table, int argc, char *argv[])
{
	table->forks = NULL;
	table->philos = NULL;
	if (argc < 5 || argc > 6)
		return (0);
	if (!args_is_only_digit(argv))
		return (0);
	table->nb_philosopers = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]);
	table->time_to_eat = ft_atol(argv[3]);
	table->time_to_sleep = ft_atol(argv[4]);
	if (argc == 6)
		table->nb_must_eat = ft_atol(argv[5]);
	else
		table->nb_must_eat = -1;
	if (table->nb_philosopers < 0 || table->time_to_die < 0
		|| table->time_to_eat < 0 || table->time_to_sleep < 0)
		return (0);
	table->start_time = 0;
	table->full_philos = 0;
	table->sim_end = 0;
	return (1);
}

int	main(int argc, char *argv[])
{
	t_table	table;

	if (!get_args(&table, argc, argv))
		error_exit("Wrong argumets iput", &table);
	if (table.nb_philosopers > 0)
	{
		if (!init_forks(&table))
			error_exit("Init mutex error", &table);
		if (!init_philos(&table))
			error_exit("Init philo error", &table);
		if (!init_threads(&table))
			error_exit("Init thread error", &table);
	}
	clean_data(&table);
}
