/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abausa-v <abausa-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:17:10 by abausa-v          #+#    #+#             */
/*   Updated: 2024/10/08 11:54:33 by abausa-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_arg_content(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	check_valid_args(char **argv)
{
	if (ft_atoi(argv[1]) > PHILO_MAX || ft_atoi(argv[1]) <= 0
		|| check_arg_content(argv[1]) == 1)
		handle_error("Invalid philosophers number\n", 1);
	if (ft_atoi(argv[2]) <= 0 || check_arg_content(argv[2]) == 1)
		handle_error("Invalid time to die\n", 1);
	if (ft_atoi(argv[3]) <= 0 || check_arg_content(argv[3]) == 1)
		handle_error("Invalid time to eat\n", 1);
	if (ft_atoi(argv[4]) <= 0 || check_arg_content(argv[4]) == 1)
		handle_error("Invalid time to sleep\n", 1);
	if (argv[5] && (ft_atoi(argv[5]) < 0 || check_arg_content(argv[5]) == 1))
		handle_error("Invalid number of times each philosopher must eat\n", 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_program		program;
	t_philo			philos[PHILO_MAX];
	pthread_mutex_t	forks[PHILO_MAX];

	if (argc != 5 && argc != 6)
		handle_error("Wrong argument count\n", 1);
	if (check_valid_args(argv) == 1)
		return (1);
	init_program(&program, philos);
	init_forks(forks, ft_atoi(argv[1]));
	init_philos(philos, &program, forks, argv);
	thread_create(&program, forks);
	destory_all(NULL, &program, forks);
	return (0);
}
