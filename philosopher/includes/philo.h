/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:43:39 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/08/12 14:50:53 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>

typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	long long		check_d_time;
	int				eat_cnt;
	struct s_game	*game;
	pthread_t		thread_id;
}				t_philo;

typedef struct s_game
{
    int         philo_num;
    int         time_to_die;
    int         time_to_eat;
    int         time_to_sleep;
    int         must_eat_num;
    pthread_mutex_t *fork;
    pthread_mutex_t	write_mutex;
	pthread_mutex_t	die_mutex;
    t_philo *philo;
}				t_game;


//check_input.c
int check_first_valid(int ac, char **av);
int is_digit(char *str);
int check_second_valid(t_game *game, int ac);

//utils.c
int is_space(char ch);
int check_integer_atoi(long num);
long    ft_atoi(const char *str);

//init.c
void init_input(t_game *game, int ac, char **av);
int init_mutex(t_game *game);
int init_philosopher(t_game *game);

#endif