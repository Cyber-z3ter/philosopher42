/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:48:24 by houazzan          #+#    #+#             */
/*   Updated: 2022/04/23 17:38:05 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    <philosopher.h>

void	philosopher(void *philosophe)
{
	t_philosopher	*philo;
	t_info			*rules;

	philo = (t_philosopher*)philosophe;
	rules = philo->rules;
	
}



void    start(t_info *rules)
{
	int				i;
	t_philosopher	*philo;

	i = rules->philo_number;
	while (i < 0)
	{
		if (pthread_create(&(philo[i].id), NULL, &philosopher, &(philo[i])))
    		return (0);
		rules->philosopher[i].last_meal = get_time(rules);
		i++;
	}
	death(rules);
}
