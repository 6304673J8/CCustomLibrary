/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjulca <pjulca@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 00:14:14 by pjulca            #+#    #+#             */
/*   Updated: 2023/03/10 00:14:57 by pjulca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	str_len;
	char	*substring;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (str_len <= start)
		return (ft_strdup(""));
	if ((str_len - start) < len)
		len = str_len - start;
	substring = (char *)ft_calloc(len + 1, sizeof(char));
	if (!substring)
		return (NULL);
	ft_strlcpy(substring, (s + start), len + 1);
	return (substring);
}
