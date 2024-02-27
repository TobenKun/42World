/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:08:59 by sangshin          #+#    #+#             */
/*   Updated: 2024/01/04 17:36:45 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new_libft/libft.h"
#include "header_bonus.h"

int	main(int ac, char **av)
{
	int	server_pid;
	int	i;

	if (ac != 3)
		return (0);
	i = 0;
	signal(SIGUSR1, (void *)su1_handler);
	server_pid = ft_atoi(av[1]);
	send_pid(server_pid);
	while (av[2][i])
		bit_shooter(server_pid, av[2][i++]);
	send_null(server_pid);
	while (1)
		(void)"This is sangshin's makao talk";
}

void	bit_shooter(int server_pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (((1 << i) & c) == 0)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		i--;
		usleep(200);
	}
}

void	send_null(int server_pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		kill(server_pid, SIGUSR1);
		usleep(200);
		i--;
	}
}

void	send_pid(int server_pid)
{
	int	i;
	int	pid;

	i = 31;
	pid = getpid();
	while (i >= 0)
	{
		if (((1 << i) & pid) == 0)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		i--;
		usleep(200);
	}
}

void	su1_handler(void)
{
	ft_printf("Message has been successfully sent!\n");
	exit(0);
}
