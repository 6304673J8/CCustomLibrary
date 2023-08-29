/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjulca <pjulca@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 00:21:23 by pjulca            #+#    #+#             */
/*   Updated: 2023/03/10 00:22:19 by pjulca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*base;
	void	*function_copy;

	new_list = 0;
	if (lst == NULL | f == NULL)
	{
		return (NULL);
	}
	while (lst)
	{
		function_copy = (f)(lst->content);
		base = ft_lstnew(function_copy);
		if (base == NULL)
		{
			ft_lstclear(&new_list, del);
			free(function_copy);
			return (NULL);
		}
		ft_lstadd_back(&new_list, base);
		lst = lst->next;
	}
	return (new_list);
}
