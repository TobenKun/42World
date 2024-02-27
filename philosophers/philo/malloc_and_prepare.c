/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_and_prepare.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:34:26 by sangshin          #+#    #+#             */
/*   Updated: 2024/02/24 17:38:12 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_new.h"
#include <pthread.h>

int	malloc_everything(t_info *info, pthread_t **thread, t_philo **philo)
{
	int	i;

	i = 0;
	*thread = malloc(sizeof(pthread_t) * (info->number_of_philo + 1));
	*philo = malloc(sizeof(t_philo) * info->number_of_philo);
	if (*thread == 0 || *philo == 0)
		return (1);
	while (i < info->number_of_philo)
	{
		(*philo)[i].info = info;
		(*philo)[i].num = i + 1;
		(*philo)[i].eat_count = 0;
		(*philo)[i].last_eat = 0;
		(*philo)[i].left_fork = i;
		(*philo)[i].right_fork = (i + 1) % info->number_of_philo;
		(*philo)[i].is_finished = 0;
		i++;
	}
	return (0);
}

int	prepare_for_dinner(t_info *info)
{
	int	i;

	i = 0;
	memset(info->fork, 0, sizeof(int) * 200);
	while (i < info->number_of_philo)
	{
		if (pthread_mutex_init(&info->mutex[i], 0))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&info->print, 0)
		|| pthread_mutex_init(&info->info, 0))
		return (1);
	return (0);
}

int	free_malloc(t_info *info, pthread_t *thread, t_philo *philo, int ret)
{
	if (info)
		free(info);
	if (thread)
		free(thread);
	if (philo)
		free(philo);
	return (ret);
}
