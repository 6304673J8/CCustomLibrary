/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjulca <pjulca@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 23:53:37 by pjulca            #+#    #+#             */
/*   Updated: 2023/03/09 23:53:46 by pjulca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = 0;
	j = 0;
	ptr = (char *)haystack;
	if (*needle == '\0')
		return (ptr);
	while (ptr[i] != '\0' && i < len)
	{
		j = 0;
		while (ptr[i + j] == needle[j] && ptr[i + j] != '\0')
		{
			if ((needle[j + 1] == '\0') && (i + j < len))
			{
				return (&ptr[i]);
			}
			j++;
		}
		i++;
	}
	return (0);
}
