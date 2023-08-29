/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjulca <pjulca@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 23:46:19 by pjulca            #+#    #+#             */
/*   Updated: 2023/03/09 23:46:27 by pjulca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_cpy;
	char		*src_cpy;

	dst_cpy = (char *)dst;
	src_cpy = (char *)src;
	if (!dst && !src)
		return (NULL);
	if (src_cpy > dst_cpy)
	{
		ft_memcpy(dst, src, len);
	}
	else
	{
		while (len--)
		{
			ft_memset(&dst[len], src_cpy[len], 1);
		}
	}
	return (dst_cpy);
}
