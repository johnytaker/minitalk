/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:33:06 by iugolin           #+#    #+#             */
/*   Updated: 2022/01/30 20:03:06 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

void	print_pid(void)
{
	ft_putendl_fd("\n¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯", 1);
	ft_putstr_fd("Succefully started 'Minitalk server'\nProcess ID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putendl_fd("\n____________________________________", 1);
}

static void	ft_error_handler(void)
{
	ft_putendl_fd("SIGNAL ERROR!", 1);
	exit(EXIT_FAILURE);
}

static void	signal_handler(int signum, siginfo_t *s_act, void *old)
{
	static unsigned char	c = 0;
	static pid_t			pid = 0;
	static size_t			size = 8;

	old = NULL;
	if (pid != s_act->si_pid)
	{
		pid = s_act->si_pid;
		c = 0;
		size = 8;
	}
	size--;
	if (signum == SIGUSR1)
		c |= 0x01 << size;
	if (size == 0)
	{
		write(1, &c, 1);
		c = 0;
		size = 8;
	}
}

int	main(void)
{
	struct sigaction	s_act;

	print_pid();
	s_act.sa_flags = SA_SIGINFO;
	s_act.sa_sigaction = signal_handler;
	if (sigaction(SIGUSR1, &s_act, NULL) != 0)
		ft_error_handler();
	if (sigaction(SIGUSR2, &s_act, NULL) != 0)
		ft_error_handler();
	while (1)
		pause();
	return (0);
}
