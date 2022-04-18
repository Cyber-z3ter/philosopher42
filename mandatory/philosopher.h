/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:08:33 by houazzan          #+#    #+#             */
/*   Updated: 2022/04/18 21:33:09 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <pthread.h>

/* **************************************************** */
/*                  🅳🅰🆃🅰 🆂🆃🆁🆄🅲🆃                  */
/* **************************************************** */
typedef struct philosopher
{
	int			id;
	int			left_fork_id;
	int			right_fork_id;
	pthread_t	tread_id;

}	t_philosopher;

typedef struct info
{
	int				philo_number;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				number_of_meals;
	int				ate;
	int				died;
	pthread_mutex_t	forks;
	pthread_mutex_t	meals;
	t_philosopher	philosopher[];
}	t_info;


/* **************************************************** */
/*             🆁🅴🅶🆄🅻🅰🆁 🅵🆄🅽🅲🆃🅸🅾🅽🆂             */
/* **************************************************** */

int	ft_atoi(char const *str);
int	ft_strlen(char *str);

#endif