/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjulca <pjulca@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 23:45:08 by pjulca            #+#    #+#             */
/*   Updated: 2023/03/09 23:45:26 by pjulca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*test;

	test = (unsigned char *)s;
	if (n == 0)
		return ;
	while (n > 0)
	{
		*(test++) = 0;
		n--;
	}
}
