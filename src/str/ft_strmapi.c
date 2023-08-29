/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjulca <pjulca@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 00:03:01 by pjulca            #+#    #+#             */
/*   Updated: 2023/08/29 20:20:49 by pjulca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str_len;
	size_t	i;

	str_len = malloc(ft_strlen(s) + 1);
	i = 0;
	if (str_len == NULL)
		return (NULL);
	while (i < ft_strlen(s))
	{
		str_len[i] = f(i, s[i]);
		i++;
	}
	str_len[ft_strlen(s)] = '\0';
	return (str_len);
}
