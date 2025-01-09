/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 15:54:11 by sangshin          #+#    #+#             */
/*   Updated: 2024/06/24 12:10:48 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	main(int ac, char **av)
{
	t_info	info;
	pid_t	*pid;

	read_arg(ac, av, &info);
	pid = ready_for_dinner(&info);
	start_simulation(&info, pid);
	free(pid);
	exit(0);
}

pid_t	*ready_for_dinner(t_info *info)
{
	pid_t	*pid;

	sem_unlink("sem");
	sem_unlink("print");
	info->sem = sem_open("sem", O_CREAT | O_EXCL, 0644, info->number_of_philo);
	if (info->sem == SEM_FAILED || sem_unlink("sem") == -1)
		exit(1);
	info->print = sem_open("print", O_CREAT | O_EXCL, 0644, 1);
	if (info->print == SEM_FAILED || sem_unlink("print") == -1)
		exit(1);
	pid = malloc(sizeof(pid_t) * info->number_of_philo);
	if (pid == 0)
		exit(1);
	memset(pid, -1, sizeof(pid_t) * info->number_of_philo);
	return (pid);
}
