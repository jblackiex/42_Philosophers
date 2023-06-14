/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbordoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 19:07:52 by nbordoni          #+#    #+#             */
/*   Updated: 2023/06/09 19:07:53 by nbordoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phil.h"

void	init_elem_0(t_philo *p)
{
	p->eating_times = 0;
	p->all_ate = 0;
	p->died = 0;
	p->i = 0;
}

long long	diff_times(long long pres, long long past)
{
	return (pres - past);
}

long long	actual_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

int	ft_atoi_limits(const char *str)
{
	long	i;
	long	nbr;
	int		isneg;

	i = 0;
	nbr = 0;
	isneg = 0;
	while (str[i] != '\0' && (str[i] == 32 || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] != '\0' && str[i] == '-')
	{
		isneg = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && (str[i] >= 48 && str[i] <= 57))
		nbr = (nbr * 10) + (str[i++] - '0');
	if (isneg == 1)
		nbr *= -1;
	if (nbr < -2147483648 || nbr > 2147483648)
		print_check_errors(NULL, -42);
	return ((int)nbr);
}

void	exit_ft(t_philo *p)
{
	int	i;

	i = -1;
	pthread_join(p->monitor, NULL);
	while (++i < p->n_philos)
		pthread_join(p->philos[i].thread, NULL);
	i = -1;
	while (++i < p->n_philos)
		pthread_mutex_destroy(&(p->fork[i]));
	pthread_mutex_destroy(&(p->print));
	pthread_mutex_destroy(&(p->check_ok));
	pthread_mutex_destroy(&(p->mutx));
}
