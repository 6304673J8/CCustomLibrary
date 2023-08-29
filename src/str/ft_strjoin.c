/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjulca <pjulca@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 00:05:32 by pjulca            #+#    #+#             */
/*   Updated: 2023/03/17 01:53:09 by pjulca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_size;
	size_t	s2_size;
	char	*str_joined;

	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	str_joined = (char *)malloc(s1_size + s2_size + 1);
	if (!str_joined)
		return (NULL);
	s1_size = 0;
	s2_size = 0;
	while (s1[s1_size])
	{
		str_joined[s1_size] = s1[s1_size];
		s1_size++;
	}
	while (s2[s2_size])
	{
		str_joined[s1_size] = s2[s2_size];
		s1_size++;
		s2_size++;
	}
	str_joined[s1_size] = '\0';
	return (str_joined);
}
