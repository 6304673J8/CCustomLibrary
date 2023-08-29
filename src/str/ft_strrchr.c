/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjulca <pjulca@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 23:50:03 by pjulca            #+#    #+#             */
/*   Updated: 2023/03/09 23:50:12 by pjulca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*conv;

	conv = NULL;
	while (*s)
	{
		if (*s == (char)c)
			conv = (char *)s;
		s++;
	}
	if (c == 1024 || c == 0)
	{
		return ((char *)s);
	}
	return (conv);
}
