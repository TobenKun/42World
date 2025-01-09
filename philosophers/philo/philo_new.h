/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_new.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:09:41 by sangshin          #+#    #+#             */
/*   Updated: 2024/03/28 08:30:13 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_NEW_H
# define PHILO_NEW_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_info
{
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				fork[200];
	long long		start_time;
	pthread_mutex_t	mutex[200];
	pthread_mutex_t	print;
	pthread_mutex_t	info;
	pthread_mutex_t	start_line;
	int				game_over;
}				t_info;

typedef struct s_philo
{
	t_info			*info;
	int				num;
	int				eat_count;
	long long		last_eat;
	int				left_fork;
	int				right_fork;
	int				is_finished;
	pthread_mutex_t	self;

}				t_philo;

/* read_arg.c */
int			get_info(t_info **info, int ac, char **av);
int			ft_atoi(char *string);
/* malloc_and_prepare.c */
int			malloc_everything(
				t_info *info, pthread_t **thread, t_philo **philo);
int			prepare_for_dinner(t_info *info);
int			free_malloc(
				t_info *info, pthread_t *thread, t_philo *philo, int ret);
/* simulation.c */
int			simulation(t_info *info, t_philo *philo, pthread_t *thread);
int			genius_shin(t_philo *philo, int *func(void *philo));
void		philo_routine(t_philo *philo);
/* monitor.c */
void		*monitoring(t_philo *philo);
int			finished_check(t_philo *philo);
int			dead_check(t_philo *philo);
int			game_over_check(t_philo *philo);
void		mutex_unlock(t_philo *philo);
/* dinner_time.c */
int			get_left_fork(t_philo *philo);
int			get_right_fork(t_philo *philo);
int			eating(t_philo *philo);
int			finish_eating(t_philo *philo);
int			thinking(t_philo *philo);
/* philo_utils.c */
long long	get_millisecond(void);
void		print_status(t_philo *philo, char *status);
void		m_sleep(long long time);

#endif
