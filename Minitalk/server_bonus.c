/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 11:04:23 by avallini          #+#    #+#             */
/*   Updated: 2023/12/13 21:24:16 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	sig_handler(int sig, siginfo_t *info, void *ucontext)
{
	static unsigned char	c;
	static int				i;

	(void)ucontext;
	if (sig == SIGUSR1)
		c |= (1 << (7 - i));
	i++;
	if (i >= 8)
	{
		if (c == 0)
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR2);
		}
		else
			write(1, &c, 1);
		c = 0;
		i = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	sa.sa_sigaction = sig_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_putendl_fd("Sigaction error.", 1);
		return (1);
	}
	ft_putstr_fd("Pid: ", 1);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	while (1)
		usleep(0);
}
