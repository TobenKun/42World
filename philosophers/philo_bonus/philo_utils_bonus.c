/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:31:15 by sangshin          #+#    #+#             */
/*   Updated: 2024/04/03 18:54:58 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

long long	get_millisecond(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, 0);
	return (current_time.tv_usec / 1000 + current_time.tv_sec * 1000);
}

void	print_status(t_info *info, char *status)
{
	sem_wait(info->print);
	printf("%.5lld %d %s\n",
		get_millisecond() - info->start_time,
		info->my_number, status);
	sem_post(info->print);
}

void	m_sleep(long long time, t_info *info)
{
	long long	start;
	long long	end;

	info = 0;
	start = get_millisecond();
	end = get_millisecond();
	while ((end - start) < time)
	{
		usleep(200);
		end = get_millisecond();
	}
}

void	ft_itoa(char *name, t_info *info)
{
	int	my_number;

	my_number = info->my_number;
	name[0] = my_number / 100 + '0';
	name[1] = (my_number % 100) / 10 + '0';
	name[2] = my_number % 10 + '0';
	name[3] = 0;
}
