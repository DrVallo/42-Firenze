/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 11:04:16 by avallini          #+#    #+#             */
/*   Updated: 2023/12/13 22:00:09 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_sig_received = 0;

void	sig_handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)sig;
	(void)info;
	(void)ucontext;
	g_sig_received = 1;
}

int	send_signal(int pid, char c)
{
	int	call_count;
	int	i;

	i = 0;
	while (i < 8)
	{
		call_count = 0;
		g_sig_received = 0;
		if (c >> (7 - i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_sig_received != 1)
		{
			usleep(10);
			call_count++;
			if (call_count >= 50)
			{
				ft_putendl_fd("Communication error with the server.", 1);
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int					i;
	int					pid;
	struct sigaction	sa;

	i = 0;
	sa.sa_sigaction = sig_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (1);
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			if (!send_signal(pid, argv[2][i++]))
				return (0);
		}
		if (!send_signal(pid, 0))
			return (0);
	}
	else
		ft_putendl_fd("How to use: ./client <server_pid> <text to send>", 1);
}
