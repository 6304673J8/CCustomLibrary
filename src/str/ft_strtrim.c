/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjulca <pjulca@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 00:05:03 by pjulca            #+#    #+#             */
/*   Updated: 2023/03/10 00:05:16 by pjulca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*string_copy;
	size_t		str_len;

	string_copy = s1;
	str_len = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (*string_copy && ft_strchr(set, *string_copy))
	{
		string_copy++;
	}
	str_len = ft_strlen(string_copy);
	while (str_len && ft_strchr(set, string_copy[str_len]))
	{
		str_len--;
	}
	return (ft_substr(string_copy, 0, str_len + 1));
}
