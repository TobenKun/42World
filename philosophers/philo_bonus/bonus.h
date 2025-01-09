/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 15:54:27 by sangshin          #+#    #+#             */
/*   Updated: 2024/04/03 18:58:12 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>
# include <pthread.h>

typedef struct s_info
{
	int				number_of_philo;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	long long		must_eat;
	int				fork;
	long long		start_time;
	long long		last_eat;
	int				game_over;
	int				my_number;
	int				eat_count;
	sem_t			*mutex;
	sem_t			*print;
	sem_t			*sem;

}					t_info;

pid_t		*ready_for_dinner(t_info *info);

// read_arg.c
void		read_arg(int ac, char **av, t_info *info);
int			ft_atoi(char *string);

// start_simulation.c
void		start_simulation(t_info *info, pid_t *pid);
void		im_your_father(t_info *info, pid_t *pid);
void		serial_killer(t_info *info, pid_t *pid);

// philo_routine.c
void		philo_routine(t_info *info);
void		philo_eat(t_info *info);
void		philo_sleep(t_info *info);
void		philo_think(t_info *info);

// monitor_thread.c
void		init_monitor_thread(t_info *info);
void		*monitor_routine(void *info);
void		death_check(t_info *info);

// philo_utils.c
long long	get_millisecond(void);
void		print_status(t_info *info, char *status);
void		m_sleep(long long time, t_info *info);
void		ft_itoa(char *name, t_info *info);

#endif
