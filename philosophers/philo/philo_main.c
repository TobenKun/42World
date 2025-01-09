/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:00:26 by sangshin          #+#    #+#             */
/*   Updated: 2024/04/03 19:06:14 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_new.h"

int	main(int ac, char **av)
{
	t_info		*info;
	pthread_t	*thread;
	t_philo		*philo;

	info = 0;
	thread = 0;
	philo = 0;
	if (!(ac == 5 || ac == 6))
		return (1);
	if (get_info(&info, ac, av)
		|| malloc_everything(info, &thread, &philo)
		|| prepare_for_dinner(info)
		|| simulation(info, philo, thread))
		return (free_malloc(info, thread, philo, 1));
	return (free_malloc(info, thread, philo, 0));
}
