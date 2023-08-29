/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjulca <pjulca@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 00:03:22 by pjulca            #+#    #+#             */
/*   Updated: 2023/03/10 00:03:56 by pjulca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	integer_check(long int integer)
{
	int	size;

	size = 0;
	if (integer == 0)
	{
		size = 1;
	}
	if (integer < 0)
	{
		integer = integer * -1;
		size++;
	}
	while (integer > 0)
	{
		integer = integer / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	long int	control_value;
	char		*str;
	int			size;

	control_value = n;
	size = integer_check(control_value);
	str = (char *)malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (NULL);
	str[size] = 0;
	if (control_value == 0)
		str[0] = 48;
	if (control_value < 0)
	{
		str[0] = '-';
		control_value = control_value * -1;
	}
	while (control_value > 0)
	{
		str[--size] = control_value % 10 + '0';
		control_value = control_value / 10;
	}
	return (str);
}
