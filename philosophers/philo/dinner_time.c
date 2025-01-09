/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:48:47 by sangshin          #+#    #+#             */
/*   Updated: 2024/05/21 07:57:12 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_new.h"

int	get_left_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->mutex[philo->left_fork]);
	if (philo->info->fork[philo->left_fork] == 0)
	{
		philo->info->fork[philo->left_fork] = 1;
		pthread_mutex_unlock(&philo->info->mutex[philo->left_fork]);
		print_status(philo, "has taken a fork");
		return (0);
	}
	pthread_mutex_unlock(&philo->info->mutex[philo->left_fork]);
	return (1);
}

int	get_right_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->mutex[philo->right_fork]);
	if (philo->info->fork[philo->right_fork] == 0)
	{
		philo->info->fork[philo->right_fork] = 1;
		pthread_mutex_unlock(&philo->info->mutex[philo->right_fork]);
		print_status(philo, "has taken a fork");
		return (0);
	}
	pthread_mutex_unlock(&philo->info->mutex[philo->right_fork]);
	return (1);
}

int	eating(t_philo *philo)
{
	print_status(philo, "is eating");
	pthread_mutex_lock(&philo->self);
	philo->last_eat = get_millisecond();
	pthread_mutex_unlock(&philo->self);
	m_sleep(philo->info->time_to_eat);
	return (0);
}

int	finish_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->self);
	philo->eat_count++;
	pthread_mutex_unlock(&philo->self);
	pthread_mutex_lock(&philo->info->mutex[philo->left_fork]);
	philo->info->fork[philo->left_fork] = 0;
	pthread_mutex_unlock(&philo->info->mutex[philo->left_fork]);
	pthread_mutex_lock(&philo->info->mutex[philo->right_fork]);
	philo->info->fork[philo->right_fork] = 0;
	pthread_mutex_unlock(&philo->info->mutex[philo->right_fork]);
	print_status(philo, "is sleeping");
	m_sleep(philo->info->time_to_sleep);
	return (0);
}

int	thinking(t_philo *philo)
{
	print_status(philo, "is thinking");
	usleep(100);
	return (0);
}
