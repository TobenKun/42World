/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:25:04 by sangshin          #+#    #+#             */
/*   Updated: 2024/04/03 18:59:18 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_new.h"

void	*monitoring(t_philo *philo)
{
	int	i;
	int	finished_philo;

	i = 0;
	finished_philo = 0;
	while (finished_philo < philo->info->number_of_philo)
	{
		if (finished_check(&philo[i]))
			finished_philo++;
		else if (dead_check(&philo[i]))
			break ;
		else
			finished_philo = 0;
		usleep(100);
		i++;
		if (i >= philo->info->number_of_philo)
			i = 0;
	}
	return (0);
}

int	finished_check(t_philo *philo)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(&philo->self);
	if (philo->is_finished == 1)
		ret = 1;
	pthread_mutex_unlock(&philo->self);
	return (ret);
}

int	dead_check(t_philo *philo)
{
	int			ret;
	long long	current_time;

	ret = 0;
	current_time = get_millisecond();
	pthread_mutex_lock(&philo->self);
	if (current_time - philo->last_eat > philo->info->time_to_die)
	{
		print_status(philo, 0);
		pthread_mutex_lock(&philo->info->info);
		philo->info->game_over = 1;
		pthread_mutex_unlock(&philo->info->info);
		ret = 1;
	}
	pthread_mutex_unlock(&philo->self);
	return (ret);
}

int	game_over_check(t_philo *philo)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(&philo->info->info);
	if (philo->info->game_over == 1)
		ret = 1;
	pthread_mutex_unlock(&philo->info->info);
	return (ret);
}
