/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_arg_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 21:12:19 by sangshin          #+#    #+#             */
/*   Updated: 2024/04/10 01:23:56 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	read_arg(int ac, char **av, t_info *info)
{
	if (!(ac == 5 || ac == 6))
		exit(1);
	info->number_of_philo = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	if (av[5] != 0)
		info->must_eat = ft_atoi(av[5]);
	else
		info->must_eat = -1;
	info->fork = 0;
	info->game_over = 0;
	info->eat_count = 0;
	info->last_eat = 0;
}

int	ft_atoi(char *string)
{
	long long	res;

	res = 0;
	while (*string)
	{
		if (*string < '0' || *string > '9')
			exit(1);
		res = res * 10 + (*string - '0');
		(string)++;
	}
	return (res);
}
