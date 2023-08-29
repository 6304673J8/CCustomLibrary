/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjulca <pjulca@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 23:47:27 by pjulca            #+#    #+#             */
/*   Updated: 2023/03/09 23:47:43 by pjulca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	dst_count;
	unsigned int	src_count;
	int				i;

	i = 0;
	dst_count = ft_strlen(dst);
	src_count = ft_strlen(src);
	if (dstsize <= dst_count)
		return (dstsize + src_count);
	while (src[i] != '\0' && dst_count + 1 < dstsize)
	{
		dst[dst_count] = src[i];
		i++;
		dst_count++;
	}
	dst[dst_count] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[i]));
}
