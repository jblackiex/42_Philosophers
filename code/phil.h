/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phil.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbordoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 19:07:29 by nbordoni          #+#    #+#             */
/*   Updated: 2023/06/09 19:07:30 by nbordoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHIL_H
# define PHIL_H

# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <unistd.h>

# define PHIL 1
# define DEATH 2
# define EAT 3
# define SLEEP 4
# define EAT_TIMES 5

//STRUCTS//
struct	s_philo;

typedef struct s_ph
{
	unsigned int	num;
	int				num_ate;
	int				next_fork;
	long long		last_pasto;
	pthread_t		thread;
	struct s_philo	*meta_b;
}	t_ph;

typedef struct s_philo
{
	t_ph			philos[250];
	long long		start_time;
	int				n_philos;
	int				death_time;
	int				all_ate;
	int				died;
	int				i;
	int				j;
	int				eat_time;
	int				sleep_time;
	int				eating_times;
	pthread_mutex_t	print;
	pthread_t		monitor;
	pthread_mutex_t	check_ok;
	pthread_mutex_t	mutx;
	pthread_mutex_t	fork[250];
}	t_philo;

//FUNCTIONS//
void		init_elem_0(t_philo *p);
long long	actual_time(void);
void		ate_plus_one(t_ph *philo);
void		philo_one(t_philo *p);
void		ft_usleep(int howlong);
long long	diff_times(long long pres, long long past);
int			ft_atoi_limits(const char *str);
void		print_check_errors(t_philo *p, int ac);
void		print_one_philo(t_philo *p);
void		start_actionss(t_ph *philo);
void		action_print(t_philo *p, int i, char *str);
void		monitor_check(t_philo *p);
void		exit_ft(t_philo *p);

#endif
