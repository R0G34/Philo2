/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abausa-v <abausa-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:17:54 by abausa-v          #+#    #+#             */
/*   Updated: 2024/10/08 11:59:02 by abausa-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_strlen(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	unsigned long long	nb;
	int					sign;
	int					i;

	nb = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (sign * nb);
}

// Destroys all the mutexes
void	destory_all(char *str, t_program *program, pthread_mutex_t *forks)
{
	int		i;
	ssize_t	ret;

	i = 0;
	if (str)
	{
		ret = write(2, str, ft_strlen(str));
		(void)ret;
		ret = write(2, "\n", 1);
		(void)ret;
	}
	pthread_mutex_destroy(&program->write_lock);
	pthread_mutex_destroy(&program->meal_lock);
	pthread_mutex_destroy(&program->dead_lock);
	while (i < program->philos[0].num_of_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

// Improved version of sleep function
int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}

// Gets the current time in milliseconds
size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		handle_error("gettimeofday() error\n", 1);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}