/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:42:49 by sangshin          #+#    #+#             */
/*   Updated: 2024/04/10 01:22:20 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	philo_routine(t_info *info)
{
	init_monitor_thread(info);
	while (1)
	{
		philo_eat(info);
		philo_sleep(info);
		philo_think(info);
	}
}

void	philo_eat(t_info *info)
{
	sem_wait(info->sem);
	sem_wait(info->sem);
	print_status(info, "has taken a fork");
	print_status(info, "has taken a fork");
	print_status(info, "is eating");
	sem_wait(info->mutex);
	info->fork += 2;
	info->last_eat = get_millisecond();
	sem_post(info->mutex);
	m_sleep(info->time_to_eat, info);
	sem_post(info->sem);
	sem_post(info->sem);
	sem_wait(info->mutex);
	info->fork -= 2;
	info->eat_count++;
	sem_post(info->mutex);
}

void	philo_sleep(t_info *info)
{
	print_status(info, "is sleeping");
	m_sleep(info->time_to_sleep, info);
}

void	philo_think(t_info *info)
{
	print_status(info, "is thinking");
	usleep(100);
}
