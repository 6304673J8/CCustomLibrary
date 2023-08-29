/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjulca <pjulca@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 23:50:26 by pjulca            #+#    #+#             */
/*   Updated: 2023/03/09 23:50:44 by pjulca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s1_copy;
	unsigned char	*s2_copy;

	s1_copy = (unsigned char *)s1;
	s2_copy = (unsigned char *)s2;
	while ((*s1_copy || *s2_copy) && n)
	{
		if (*s1_copy == *s2_copy)
		{
			s1_copy++;
			s2_copy++;
			n--;
		}
		else if (*s1_copy > *s2_copy || *s1_copy < *s2_copy)
		{
			return (*s1_copy - *s2_copy);
		}
	}
	return (0);
}
