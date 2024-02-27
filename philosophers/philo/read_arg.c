/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:14:56 by sangshin          #+#    #+#             */
/*   Updated: 2024/02/22 18:20:50 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_new.h"

int	get_info(t_info **info, int ac, char **av)
{
	*info = malloc(sizeof(t_info));
	if (info == 0)
		return (1);
	(*info)->number_of_philo = ft_atoi(av[1]);
	(*info)->time_to_die = ft_atoi(av[2]);
	(*info)->time_to_eat = ft_atoi(av[3]);
	(*info)->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		(*info)->must_eat = ft_atoi(av[5]);
	else
		(*info)->must_eat = -1;
	if ((*info)->number_of_philo == -2 || (*info)->time_to_die == -2
		|| (*info)->time_to_eat == -2 || (*info)->time_to_sleep == -2
		|| (*info)->must_eat == -2)
		return (1);
	return (0);
}

int	ft_atoi(char *string)
{
	long long	res;

	res = 0;
	while (*string)
	{
		if (*string < '0' || *string > '9')
			return (-2);
		res = res * 10 + (*string - '0');
		(string)++;
	}
	return (res);
}
