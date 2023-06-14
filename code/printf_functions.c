/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbordoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 19:08:01 by nbordoni          #+#    #+#             */
/*   Updated: 2023/06/09 19:08:02 by nbordoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phil.h"

void	print_one_philo(t_philo *p)
{
	printf("%-7li 1 Has taken a fork ♆\n", (long int) 0);
	usleep(p->death_time * 1000);
	printf("%-7li 1 is dead 👣\n", (long int)p->death_time);
}

void	action_print(t_philo *p, int i, char *str)
{
	pthread_mutex_lock(&(p->check_ok));
	if (!(p->died))
		printf("%-7lli %d %s\n", actual_time() - p->start_time, i, str);
	pthread_mutex_unlock(&(p->check_ok));
}

void	ft_usleep(int howlong)
{
	long long	tmp;

	tmp = actual_time() + howlong;
	while (actual_time() < tmp)
		usleep(100);
}

void	ate_plus_one(t_ph *philo)
{
	pthread_mutex_lock(&(philo->meta_b->check_ok));
	(philo->num_ate)++;
	pthread_mutex_unlock(&(philo->meta_b->check_ok));
}

void	start_actionss(t_ph *philo)
{
	if (philo->num % 2)
		usleep(15000);
	pthread_mutex_lock(&(philo->meta_b->print));
	while (!philo->meta_b->died && !philo->meta_b->all_ate)
	{
		pthread_mutex_unlock(&(philo->meta_b->print));
		pthread_mutex_lock(&(philo->meta_b->fork[philo->num]));
		action_print(philo->meta_b, philo->num + 1, "Has taken a fork ♆");
		pthread_mutex_lock(&(philo->meta_b->fork[philo->next_fork]));
		action_print(philo->meta_b, philo->num + 1, "Has taken a fork ♆");
		pthread_mutex_lock(&(philo->meta_b->print));
		philo->last_pasto = actual_time();
		pthread_mutex_unlock(&(philo->meta_b->print));
		action_print(philo->meta_b, philo->num + 1, "is eating 🍜");
		ft_usleep(philo->meta_b->eat_time);
		ate_plus_one(philo);
		pthread_mutex_unlock(&(philo->meta_b->fork[philo->num]));
		pthread_mutex_unlock(&(philo->meta_b->fork[philo->next_fork]));
		action_print(philo->meta_b, philo->num + 1, "is sleeping");
		ft_usleep(philo->meta_b->sleep_time);
		action_print(philo->meta_b, philo->num + 1, "is thinking");
		pthread_mutex_lock(&(philo->meta_b->print));
	}
	pthread_mutex_unlock(&(philo->meta_b->print));
}
