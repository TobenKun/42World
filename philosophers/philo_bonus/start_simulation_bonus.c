/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:41:24 by sangshin          #+#    #+#             */
/*   Updated: 2024/04/03 18:57:02 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	start_simulation(t_info *info, pid_t *pid)
{
	int	i;

	i = 0;
	info->start_time = get_millisecond();
	info->last_eat = info->start_time;
	while (i < info->number_of_philo)
	{
		pid[i] = fork();
		if (pid[i] == 0)
		{
			info->my_number = i + 1;
			philo_routine(info);
		}
		i++;
	}
	usleep(100);
	if (i == info->number_of_philo)
		im_your_father(info, pid);
}

void	im_your_father(t_info *info, pid_t *pid)
{
	int	i;
	int	exit_code;

	i = 0;
	while (i < info->number_of_philo)
	{
		waitpid(-1, &exit_code, 0);
		if ((exit_code >> 8) != 0)
		{
			serial_killer(info, pid);
			printf(
				"%.5lld %d died\n",
				get_millisecond()
				- info->start_time, exit_code >> 8);
			break ;
		}
		i++;
	}
	sem_close(info->sem);
	sem_close(info->print);
}

void	serial_killer(t_info *info, pid_t *pid)
{
	int	i;

	i = 0;
	sem_wait(info->print);
	while (i < info->number_of_philo)
	{
		kill(pid[i], SIGINT);
		i++;
	}
	sem_post(info->print);
}
