/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjulca <pjulca@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 23:45:52 by pjulca            #+#    #+#             */
/*   Updated: 2023/03/09 23:45:57 by pjulca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_cpy;
	unsigned char	*src_cpy;
	size_t			i;

	src_cpy = (unsigned char *) src;
	dst_cpy = (unsigned char *) dst;
	i = 0;
	if (!dst_cpy && !src_cpy)
		return (NULL);
	while (n--)
	{
		ft_memset(&dst[i], src_cpy[i], 1);
		i++;
	}
	return (dst_cpy);
}
