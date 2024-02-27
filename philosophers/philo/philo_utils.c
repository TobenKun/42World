/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:31:15 by sangshin          #+#    #+#             */
/*   Updated: 2024/02/27 18:13:57 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_new.h"

long long	get_millisecond(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, 0);
	return (current_time.tv_usec / 1000 + current_time.tv_sec * 1000);
}

void	print_status(t_philo *philo, char *status)
{
	static int	finish_flag;

	if (finish_flag == 1)
		return ;
	if (status == 0)
	{
		status = "died";
		finish_flag++;
	}
	pthread_mutex_lock(&philo->info->print);
	printf("%.5lld %d %s\n",
		get_millisecond() - philo->info->start_time,
		philo->num, status);
	pthread_mutex_unlock(&philo->info->print);
}

void	m_sleep(long long time)
{
	long long	start;
	long long	end;

	start = get_millisecond();
	end = get_millisecond();
	while ((end - start) < time)
	{
		usleep(100);
		end = get_millisecond();
	}
}
