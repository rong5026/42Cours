/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:42:20 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/10/18 00:55:32 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>

# define DIE 1
# define FULL 2

typedef struct s_philo
{
	pid_t				pid;
	int					id;
	sem_t				*sem_last_eat;
	sem_t				*sem_cnt_eat;
	long				last_eat;
	int					cnt_eat;
	struct s_monitor	*monitor;
}	t_philo;

typedef struct s_monitor
{
	int				philo_num;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				must_eat_flag;
	int				must_eat_num;
	sem_t			*sem_start;
	int				finish_type;
	sem_t			*sem_finish;
	int				full_cnt;
	sem_t			*sem_full;
	sem_t			*sem_print;
	sem_t			*fork;
	t_philo			*philo;
	size_t			start_time;
}	t_monitor;

// check_input_bonus.c
int		check_first_valid(int ac, char **av);
int		is_digit(char *str);
int		check_second_valid(t_monitor *monitor, int ac);

// init_bonus.c
void	init_monitor(t_monitor *monitor, int ac, char **av);
int		init_set(t_monitor *monitor);
int		init_sem(t_monitor *monitor);
int		init_philosopher(t_monitor *monitor);
void	set_philo(t_monitor *monitor, t_philo *philo, int i);

// monitor_bonus.c
void	*monitor_philo(void *arg);
int		check_die(t_philo *philo);
int		monitor_main(t_monitor *monitor);
void	*monitor_full(void *arg);

// run_bonus.c
void	start(t_monitor *monitor, int i);
void	run_take_fork(t_philo *philo);
void	run_eat(t_philo *philo);
void	run_sleep(t_philo *philo);
void	run_takeoff_fork(t_philo *philo);

// message_bonus.c
void	sem_print(char *message, t_monitor *monitor);

// action_bonus.c
int		print_take_fork_state(t_philo *philo);
int		print_eat_state(t_philo *philo);
int		print_sleep_state(t_philo *philo);
int		print_think_state(t_philo *philo);
int		print_finish_state(t_philo *philo);

// free_bonus.c
void	kill_process(t_monitor *monitor);
void	free_monitor(void);

// utils_bonus.c
int		is_space(char ch);
int		check_integer_atoi(long num);
long	ft_atoi(const char *str);
long	calc_timeval(struct timeval *start, struct timeval *end);
void	sleep_unit(t_monitor *monitor, long aim_time, \
						struct timeval start_time, long unit);	

void	eat_or_sleep_time(long do_time);
size_t	get_time(void);
#endif