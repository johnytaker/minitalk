/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:33:06 by iugolin           #+#    #+#             */
/*   Updated: 2022/01/25 19:44:47 by iugolin          ###   ########.fr       */
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

static void	signal_handler(int signum, siginfo_t *s_act, void *old)
{
	static unsigned char	c;
	static size_t			size = 8;

	(void)old;
	if (signum == SIGUSR1)
		signum = 1;
	else if (signum == SIGUSR2)
		signum = 0;
	// if (c == 0 && size == 0)
	// 	size = 8;
	size--;
	c |= (signum & 1) << size;
	if (size == 0)
	{
		if (!c)
		{
			write(1, "\n", 1);
			kill(s_act->si_pid, SIGUSR1);
		}
		write(1, &c, 1);
		c = 0;
		size = 8;
	}
}

int	main(void)
{
	struct sigaction	s_act;

	print_pid();
	s_act.sa_sigaction = signal_handler;
	s_act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_act, NULL);
	sigaction(SIGUSR2, &s_act, NULL);
	while (1)
		pause();
	return (0);
}
