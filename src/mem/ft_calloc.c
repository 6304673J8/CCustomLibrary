/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjulca <pjulca@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 23:54:27 by pjulca            #+#    #+#             */
/*   Updated: 2023/03/09 23:54:50 by pjulca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*allocated_mem;

	total_size = count * size;
	allocated_mem = malloc(total_size);
	if (allocated_mem == NULL)
		return (NULL);
	ft_memset(allocated_mem, 0, total_size);
	return (allocated_mem);
}
