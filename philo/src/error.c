/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abausa-v <abausa-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:54:16 by abausa-v          #+#    #+#             */
/*   Updated: 2024/10/08 11:59:35 by abausa-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	handle_error(char *error, int code)
{
	ssize_t	ret;

	ret = write(2, error, ft_strlen(error));
	(void)ret;
	_exit(code);
}
