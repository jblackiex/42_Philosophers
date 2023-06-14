/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbordoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 19:07:17 by nbordoni          #+#    #+#             */
/*   Updated: 2023/06/09 19:07:18 by nbordoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phil.h"

void	print_check_errors(t_philo *p, int ac)
{
	int	count;

	count = 0;
	if (ac == -42)
	{
		printf("INPUT IS TOO BIG\n");
		exit(1);
	}
	if (ac < 5 || ac > 6)
	{
		printf("INVALID ARGUMENTS\n");
		exit(1);
	}
	if (p->death_time <= 0 && ++count)
		printf("Second argument MUST BE a number > 0\n");
	if (p->eat_time <= 0 && ++count)
		printf("Third argument MUST BE a number > 0\n");
	if (p->sleep_time <= 0 && ++count)
		printf("Forth argument MUST BE a number > 0\n");
	if (count)
		exit(1);
}

void	check_av_save(char **av, t_philo *p, int ac)
{
	int		i;

	p->n_philos = ft_atoi_limits(av[PHIL]);
	if (p->n_philos <= 0 || p->n_philos >= 250)
		print_check_errors(p, 2);
	p->death_time = ft_atoi_limits(av[DEATH]);
	p->eat_time = ft_atoi_limits(av[EAT]);
	p->sleep_time = ft_atoi_limits(av[SLEEP]);
	if (ac == 6)
	{
		p->eating_times = ft_atoi_limits(av[EAT_TIMES]);
		if (p->eating_times <= 0)
			print_check_errors(p, 4);
	}
	print_check_errors(p, ac);
	i = -1;
	while (++i < p->n_philos)
	{
		p->philos[i].num = i;
		p->philos[i].next_fork = i + 1;
		p->philos[i].last_pasto = 0;
		p->philos[i].meta_b = p;
		p->philos[i].num_ate = 0;
	}
}

int	init_mutex(t_philo *p)
{
	int	i;
	int	mut;
	int	mut2;
	int	mut3;

	i = -1;
	mut = 0;
	mut2 = 0;
	mut3 = 0;
	if (p->n_philos == 1)
		philo_one(p);
	i = -1;
	while (++i < p->n_philos && !mut)
		mut = pthread_mutex_init(&p->fork[i], NULL);
	mut2 = pthread_mutex_init(&(p->print), NULL);
	mut3 = pthread_mutex_init(&(p->check_ok), NULL);
	pthread_mutex_init(&(p->mutx), NULL);
	if (mut || mut2 || mut3)
		return (1);
	p->fork[i] = p->fork[0];
	return (0);
}

void	lessgo(t_philo *p)
{
	int		i;
	t_ph	*philo;

	i = -1;
	philo = p->philos;
	p->start_time = actual_time();
	pthread_create(&p->monitor, NULL, (void *) monitor_check, p);
	while (++i < p->n_philos)
		pthread_create(&(philo[i].thread), NULL,
			(void *) start_actionss, &(philo[i]));
}

int	main(int ac, char **av)
{
	t_philo	p;

	init_elem_0(&p);
	if (ac == 5 || ac == 6)
		check_av_save(av, &p, ac);
	else
		print_check_errors(&p, ac);
	if (init_mutex(&p))
		return (printf("failed to init mutex\n"), 1);
	lessgo(&p);
	exit_ft(&p);
	if (p.all_ate)
		printf("--> ALL ATE.. %d TIMES <--\n", p.eating_times);
	return (0);
}
