/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjulca <pjulca@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 23:53:58 by pjulca            #+#    #+#             */
/*   Updated: 2023/03/09 23:54:10 by pjulca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_if_space(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t	number;
	size_t	flag_negative;

	number = 0;
	flag_negative = 1;
	while (ft_check_if_space(*str) == 1)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
		{
			flag_negative *= -1;
		}
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + *str - '0';
		str++;
	}
	return (number * flag_negative);
}
