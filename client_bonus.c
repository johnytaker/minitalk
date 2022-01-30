/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:36:12 by iugolin           #+#    #+#             */
/*   Updated: 2022/01/30 19:46:13 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

static void	usage(void)
{
	ft_putendl_fd("\n¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯", 1);
	ft_putendl_fd("Error. Make sure that the server is launched.", 1);
	ft_putendl_fd("Launch server: ./server", 1);
	ft_putendl_fd("Launch client: ./client [server_pid] [string]", 1);
	ft_putendl_fd("_____________________________________________", 1);
}

static void	ft_error_handler(void)
{
	ft_putendl_fd("SIGNAL ERROR!", 1);
	exit(EXIT_FAILURE);
}

static void	ft_handler(int signum)
{
	(void)signum;
}

static void	string_delivery(char *str, pid_t pid)
{
	static size_t	bitnum;
	size_t			i;

	i = 0;
	while (str[i])
	{
		bitnum = 8;
		while (bitnum--)
		{
			if ((str[i] >> bitnum) & 0x01)
			{
				if (kill(pid, SIGUSR1) != 0)
					ft_error_handler();
			}
			else
			{
				if (kill(pid, SIGUSR2) != 0)
					ft_error_handler();
			}
			pause();
			usleep(50);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (argc != 3)
	{
		usage();
		return (-1);
	}
	ft_putstr_fd("Sending data to : ", 1);
	ft_putstr_fd(argv[1], 1);
	ft_putendl_fd("..", 1);
	sa.sa_handler = ft_handler;
	if (sigaction(SIGUSR1, &sa, NULL) != 0)
		ft_error_handler();
	string_delivery(argv[2], ft_atoi(argv[1]));
	return (0);
}
