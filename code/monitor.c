/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbordoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 19:07:38 by nbordoni          #+#    #+#             */
/*   Updated: 2023/06/09 19:07:41 by nbordoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phil.h"

void	check_ate(t_philo *p)
{
	if (!(p->all_ate))
	{
		pthread_mutex_lock(&(p->check_ok));
		p->j = 0;
		while (p->eating_times && p->j < p->n_philos
			&& p->philos[p->j].num_ate >= p->eating_times)
			p->j += 1;
		if (p->j == p->n_philos)
			p->all_ate = 1;
		pthread_mutex_unlock(&(p->check_ok));
	}
}

void	monitor_check(t_philo *p)
{
	while (!(p->died) && !(p->all_ate))
	{
		p->i = 0;
		usleep(1000);
		while (p->i < p->n_philos)
		{
			pthread_mutex_lock(&(p->print));
			if (p->philos[p->i].last_pasto
				&& diff_times(actual_time(),
					p->philos[p->i].last_pasto) > p->death_time)
			{
				action_print(p, p->i + 1, "died 🕯");
				pthread_mutex_lock(&(p->check_ok));
				p->died = 1;
				pthread_mutex_unlock(&(p->check_ok));
				pthread_mutex_unlock(&(p->print));
				return ;
			}
			pthread_mutex_unlock(&(p->print));
			p->i += 1;
		}
		check_ate(p);
	}
}

void	philo_one(t_philo *p)
{
	pthread_create(&(p->philos[0].thread), NULL,
		(void *) print_one_philo, p);
	pthread_join(p->philos[0].thread, NULL);
	exit (0);
}
