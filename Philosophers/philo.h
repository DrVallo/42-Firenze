/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:41:04 by avallini          #+#    #+#             */
/*   Updated: 2024/06/15 14:56:56 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo	t_philo;

typedef struct s_table
{
	long			nb_philosopers;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_t		controller;
	pthread_mutex_t	eat_lock;
	pthread_mutex_t	print_lock;
	long			start_time;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			nb_must_eat;
	long			full_philos;
	int				sim_end;
}	t_table;

typedef struct s_philo
{
	unsigned int	id;
	unsigned int	forks[2];
	pthread_t		thread;
	long			last_eat;
	int				eat_count;
	t_table			*table;
}	t_philo;

// main.c
int		get_args(t_table *table, int argc, char *argv[]);
void	print_message(char *str, t_philo *philo);
int		is_valid_routine(t_philo *philo);

// utils.c
long	ft_atol(char *str);
int		args_is_only_digit(char *argv[]);
int		is_digit(char c);
void	ms_sleep(long time_to_sleep);
long	get_time(void);

// init_data.c
int		init_philos(t_table *table);
int		init_threads(t_table *table);
int		init_forks(t_table *table);

// philo.c
void	philo_eat(t_philo *philo);
void	*philo_routine(void *data);
int		get_forks(t_philo *philo);

// controller.c
int		is_valid_routine(t_philo *philo);
int		check_philo_death_and_full(t_table *table);
void	*controller_routine(void *data);

#endif
