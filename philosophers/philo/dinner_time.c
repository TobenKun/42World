/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:48:47 by sangshin          #+#    #+#             */
/*   Updated: 2024/02/24 17:37:38 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_new.h"

void	get_left_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->mutex[philo->left_fork]);
	philo->info->fork[philo->left_fork] = 1;
}

void	get_right_fork(t_philo *philo)
{
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(&philo->info->mutex[philo->right_fork]);
	philo->info->fork[philo->right_fork] = 1;
}

void	eating(t_philo *philo)
{
	print_status(philo, "has taken a fork");
	print_status(philo, "is eating");
	pthread_mutex_lock(&philo->self);
	philo->last_eat = get_millisecond();
	pthread_mutex_unlock(&philo->self);
	m_sleep(philo->info->time_to_eat);
}

void	finish_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->self);
	philo->eat_count++;
	pthread_mutex_unlock(&philo->self);
	philo->info->fork[philo->left_fork] = 0;
	pthread_mutex_unlock(&philo->info->mutex[philo->left_fork]);
	philo->info->fork[philo->right_fork] = 0;
	pthread_mutex_unlock(&philo->info->mutex[philo->right_fork]);
	print_status(philo, "is sleeping");
	m_sleep(philo->info->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	print_status(philo, "is thinking");
	usleep(100);
}
