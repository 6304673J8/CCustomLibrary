/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjulca <pjulca@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:31:13 by pjulca            #+#    #+#             */
/*   Updated: 2023/08/29 20:13:45 by pjulca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*ft_free_gnl(char *str[])
{
	free(*str);
	*str = NULL;
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr_gnl(char *str, int c)
{
	c = (char)c;
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == c)
			return (&(*str));
		str++;
	}
	if (c == '\0')
		return (&(*str));
	return (NULL);
}

char	*ft_strjoin_gnl(char *str_file, char *buff)
{
	char	*tmps;
	size_t	i;
	size_t	j;

	if (!str_file)
	{
		str_file = (char *)malloc(1 * sizeof(char));
		if (!str_file)
			return (NULL);
		str_file[0] = '\0';
	}
	tmps = malloc(sizeof(char) * ((ft_strlen(str_file) + ft_strlen(buff)) + 1));
	if (!tmps)
		return (ft_free_gnl(&str_file));
	i = -1;
	j = 0;
	if (str_file)
		while (str_file[++i] != '\0')
			tmps[i] = str_file[i];
	while (buff[j] != '\0')
		tmps[i++] = buff[j++];
	tmps[i] = '\0';
	free(str_file);
	return (tmps);
}
