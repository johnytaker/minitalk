/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:36:12 by iugolin           #+#    #+#             */
/*   Updated: 2022/01/24 19:39:19 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

static int	usage(void)
{
	ft_putendl_fd("\n¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯", 1);
	ft_putendl_fd("Error. Make sure that the server is launched.", 1);
	ft_putendl_fd("Launch server: ./server", 1);
	ft_putendl_fd("Launch client: ./client [server_pid] [string]", 1);
	ft_putendl_fd("_____________________________________________", 1);
	return (0);
}

static void	ft_handler(int signum)
{
	(void)signum;
	ft_putendl_fd("Signal Received !", 1);
	exit(EXIT_SUCCESS);
}

static void	string_delivery(char *str, pid_t pid)
{
	size_t	bitnum;
	size_t	str_len;
	size_t	i;

	str_len = ft_strlen(str);
	i = 0;
	while (str_len >= i)
	{
		bitnum = 8;
		while (bitnum--)
		{
			if ((str[i] >> bitnum) & 0x01)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(160);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		usage();
		return (-1);
	}
	ft_putstr_fd("Sending data to : ", 1);
	ft_putstr_fd(argv[1], 1);
	ft_putendl_fd("..", 1);
	// if (signal(SIGUSR1, ft_handler) == -1 || signal(SIGUSR2, ft_handler) == -1)
	// 	{
	// 		ft_putendl_fd("An error has occurred", 1);
	// 		exit(EXIT_FAILURE);
	// 	}
	signal(SIGUSR1, ft_handler);
	string_delivery(argv[2], ft_atoi(argv[1]));
	return (0);
}
