/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misikogl <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:08:51 by misikogl          #+#    #+#             */
/*   Updated: 2022/12/21 02:22:57 by misikogl         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <stdbool.h>

typedef struct s_philo
{
	int				id;
	int				left_fork_id;
	int				right_fork_id;
	long long		last_meal;
	int				max_can_eat;
	struct s_rule	*rule;
	pthread_t		thread;
}	t_philo;

typedef struct s_rule
{
	int				philo_nbr;
	int				time_to_die;
	int				time_to_sleep;
	int				time_to_eat;
	int				is_dead;
	long long		start_time;
	int				temp_eat;
	int				must_eat;
	pthread_mutex_t	forks[250];
	pthread_mutex_t	meal_check;
	pthread_mutex_t	writing;
	pthread_mutex_t	lock;
	t_philo			philo[250];
}	t_rule;

/*error.c*/
int			errorcheck(int argc, char **argv);
int			errorcheck_two(int argc, char **argv);
void		writerror(int exit_mode);
int			error_manager(int error);
int			write_error(char *str);

/*philosophers.c*/
int			main(int argc, char **argv);

/*utils.c*/
int			is_al_num(char *argv);
int			ft_atoi(char *str);
void		reset(void);

/*initialize.c*/
int			ft_init_rule(t_rule *rule, char **argv);
int			ft_init_mutex(t_rule *rule);
void		pick_color(int color);
void		philo_init(t_rule *rule);

/*dinner.c*/
void		ft_eat_philos(t_philo *philo);
void		*ft_dinner(void *philos);

/*create_threads.c*/
int			create_threads(t_rule *rule);

/*check.c*/
void		print_philo(t_rule *philo, int id, char *string, int color);
void		check_death(t_rule *rule, t_philo *philo);
void		check_death_two(t_rule *rule, t_philo *philo);

/*color.c*/
void		red(void);
void		yellow(void);
void		green(void);
void		blue(void);
void		purple(void);

/*time.c*/
void		ft_timing(long long time, t_rule *rule);
long long	start_time(void);
long long	calculate_time(long long present, long long past);

/*free.c*/
void		exit_thread(t_rule *rule, t_philo *philo);

#endif
