/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_thread_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:43:33 by sangshin          #+#    #+#             */
/*   Updated: 2024/04/10 01:22:54 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	init_monitor_thread(t_info *info)
{
	char		name[4];
	pthread_t	thread;

	ft_itoa(name, info);
	info->mutex = sem_open(name, O_CREAT | O_EXCL, 0644, 1);
	if (info->mutex == SEM_FAILED || sem_unlink(name) == -1)
		exit(-1);
	if (pthread_create(&thread, 0, monitor_routine, info))
		exit(-1);
	pthread_detach(thread);
}

void	*monitor_routine(void *arg)
{
	t_info	*info;

	info = arg;
	while (1)
	{
		sem_wait(info->mutex);
		death_check(info);
		sem_post(info->mutex);
		usleep(100);
	}
	return (0);
}

void	death_check(t_info *info)
{
	sem_wait(info->print);
	if (info->must_eat != -1 && info->eat_count == info->must_eat)
	{
		if (info->fork)
		{
			sem_post(info->sem);
			sem_post(info->sem);
		}
		sem_close(info->mutex);
		sem_post(info->print);
		exit(0);
	}
	if (get_millisecond() - info->last_eat > info->time_to_die)
	{
		sem_close(info->mutex);
		sem_post(info->print);
		exit(info->my_number);
	}
	sem_post(info->print);
}
