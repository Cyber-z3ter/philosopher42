/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:08:33 by houazzan          #+#    #+#             */
/*   Updated: 2022/05/16 18:59:48 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <signal.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <semaphore.h>
# define MAX_INT 2147483647
# define MIN_INT -2147483648

/* **************************************************** */
/*                  🅳🅰🆃🅰 🆂🆃🆁🆄🅲🆃                  */
/* **************************************************** */
typedef struct s_philosopher
{
	int				id;
	int				n_ate;
	int				left_fork_id;
	int				right_fork_id;
	int				pid;
	long long		last_meal_time;
	struct s_info	*rules;
	pthread_t		thread_id;

}	t_philosopher;

typedef struct s_info
{
	int				philo_number;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				number_of_meals;
	int				all_ate;
	int				died;
	long long		first_time;
	sem_t			*forks;
	sem_t			*write;
}	t_info;

/* **************************************************** */
/*             🆁🅴🅶🆄🅻🅰🆁 🅵🆄🅽🅲🆃🅸🅾🅽🆂             */
/* **************************************************** */

int			ft_atoi(char const *str);
int			ft_strlen(char *str);
int			ft_clear(void);
int			ft_error(char *str);
void		start(t_info *rules, t_philosopher *philosopher);
void		printing(t_info *rules, int id, char *str);
int			init_mutex(t_info *rules);
long long	get_time(void);
long long	time_diff(long long then, long long now);
void		p_death( void *philo);
void		exiting(t_info *rules, t_philosopher *philosopher);
void		printing(t_info *rules, int id, char *str);
void		sleep_time(int time, t_info *rules);

#endif
