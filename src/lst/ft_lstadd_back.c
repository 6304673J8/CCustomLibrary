/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjulca <pjulca@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 00:26:43 by pjulca            #+#    #+#             */
/*   Updated: 2023/03/10 00:26:48 by pjulca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*base;

	base = *lst;
	if (base == NULL)
	{
		*lst = new;
		return ;
	}
	if (new != NULL)
	{
		base = ft_lstlast(*lst);
		base->next = new;
	}
}
