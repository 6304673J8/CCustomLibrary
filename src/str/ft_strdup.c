/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjulca <pjulca@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 23:55:03 by pjulca            #+#    #+#             */
/*   Updated: 2023/03/09 23:55:07 by pjulca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*s_copy;

	len = ft_strlen(s1) + 1;
	s_copy = malloc(len);
	if (s_copy == NULL)
		return (NULL);
	ft_memcpy(s_copy, s1, len);
	return (s_copy);
}
