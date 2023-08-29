/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjulca <pjulca@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 23:44:45 by pjulca            #+#    #+#             */
/*   Updated: 2023/03/09 23:44:53 by pjulca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;
	unsigned char	c_copy;

	p = (unsigned char *) b;
	c_copy = (unsigned char) c;
	while (len--)
	{
		*p++ = c_copy;
	}
	return (b);
}
