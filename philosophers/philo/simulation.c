/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:26:19 by sangshin          #+#    #+#             */
/*   Updated: 2024/02/24 18:34:00 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_new.h"

int	simulation(t_info *info, t_philo *philo, pthread_t *thread)
{
	int	i;

	info->game_over = 0;
	info->start_time = get_millisecond();
	pthread_mutex_init(&info->start_line, 0);
	pthread_mutex_lock(&info->start_line);
	i = -1;
	while (++i < info->number_of_philo)
	{
		philo[i].last_eat = info->start_time;
		pthread_mutex_init(&philo[i].self, 0);
		if (pthread_create(&thread[i], 0, (void *)philo_routine, &philo[i]))
			return (1);
	}
	pthread_mutex_unlock(&info->start_line);
	pthread_create(&thread[i], 0, (void *)monitoring, philo);
	pthread_join(thread[i], 0);
	i = -1;
	while (++i < info->number_of_philo)
		pthread_join(thread[i], 0);
	return (0);
}

void	philo_routine(t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&philo->info->start_line);
	pthread_mutex_unlock(&philo->info->start_line);
	if (philo->num % 2 == 0)
		m_sleep((philo->info->time_to_eat / 2) + 1);
	while (1)
	{
		if (genius_shin(philo, (void *)get_left_fork)
			|| genius_shin(philo, (void *)get_right_fork)
			|| genius_shin(philo, (void *)eating)
			|| genius_shin(philo, (void *)finish_eating)
			|| genius_shin(philo, (void *)thinking)
		)
			break ;
	}
	mutex_unlock(philo);
	pthread_mutex_lock(&philo->self);
	philo->is_finished = 1;
	pthread_mutex_unlock(&philo->self);
}

int	genius_shin(t_philo *philo, void *func(void *))
{
	if (philo->eat_count == philo->info->must_eat || game_over_check(philo))
		return (1);
	func(philo);
	return (0);
}
