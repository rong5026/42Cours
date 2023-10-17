/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:43:39 by yeohong           #+#    #+#             */
/*   Updated: 2023/08/14 11:29:14 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	size_t			last_eat_time;
	int				eat_cnt;
	int				alive;
	struct s_game	*game;
	pthread_t		thread_id;
}				t_philo;

typedef struct s_game
{
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_num;
	int				die;
	size_t			start_time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	eating;
	pthread_mutex_t	printing;
	pthread_mutex_t	die_mutex;
	pthread_mutex_t	philo_eat;
	pthread_mutex_t	philo_alive;
	t_philo			*philo;
}				t_game;

//check_input.c
int		check_first_valid(int ac, char **av);
int		is_digit(char *str);
int		check_second_valid(t_game *game, int ac);

//utils.c
int		is_space(char ch);
int		check_integer_atoi(long num);
long	ft_atoi(const char *str);
void	print_time(char *str, t_game *game, t_philo *philo);
void	print_dead(t_game *game, t_philo *philo);

//init.c
void	init_input(t_game *game, int ac, char **av);
int		init_mutex(t_game *game);
int		init_philosopher(t_game *game);

//time.c
size_t	get_time(void);
void	eat_or_sleep_time(size_t do_time);
void	one_philo_time(t_game *game);

//action.c
int		take_fork(t_philo *philo, t_game *game);
int		take_eat(t_philo *philo, t_game *game);
int		take_sleep(t_philo *philo, t_game *game);
int		take_think(t_philo *philo, t_game *game);
int		check_die_elem(t_game *game);

//run.c
int		start_philo(t_game *game, t_philo *philo);
void	*run_thread(void *philo);
void	start_death_check(t_game *game);
void	starving_death(t_game *game);
void	full_eat_death(t_game *game);

//free.c
void	end_philo(t_game *game);
void	end_thread(t_game *game);
void	unlock_and_destroy(t_game *game);
void	malloc_free(t_game *game);

//get_set.c
int		get_die(t_game *game);
void	set_die(t_game *game, int sign);
int		get_alive(t_game *game, t_philo *philo);
void	set_alive(t_game *game, t_philo *philo, int sign);
#endif