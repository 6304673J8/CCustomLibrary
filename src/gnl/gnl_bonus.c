/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjulca <pjulca@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:33:00 by pjulca            #+#    #+#             */
/*   Updated: 2023/08/29 20:14:00 by pjulca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*full_read(int fd, char *file_text)
{
	int		bytes;
	char	*buffer;

	bytes = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free_gnl(&file_text));
	while (!ft_strchr_gnl(file_text, '\n') && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			return (ft_free_gnl(&file_text));
		}
		buffer[bytes] = '\0';
		file_text = ft_strjoin_gnl(file_text, buffer);
	}
	free(buffer);
	return (file_text);
}

char	*line_read(char *file_text)
{
	int		bytes;
	char	*buffer;

	bytes = 0;
	if (file_text[bytes] == '\0')
		return (NULL);
	while (file_text[bytes] && file_text[bytes] != '\n')
		bytes++;
	if (file_text[bytes] != '\n')
		buffer = (char *)malloc(sizeof(char) * (bytes + 1));
	else
		buffer = (char *)malloc(sizeof(char) * (bytes + 2));
	if (!buffer)
		return (NULL);
	bytes = 0;
	while (file_text[bytes] && file_text[bytes] != '\n')
	{
		buffer[bytes] = file_text[bytes];
		bytes++;
	}
	if (file_text[bytes] == '\n')
		buffer[bytes++] = '\n';
	buffer[bytes] = '\0';
	return (buffer);
}

char	*partial_read(char *file_text)
{
	int		i;
	int		j;
	char	*buffer;

	i = 0;
	j = 0;
	while (file_text[i] && file_text[i] != '\n')
		i++;
	if (file_text[i] == '\0')
		return (ft_free_gnl(&file_text));
	buffer = (char *)malloc(sizeof(char) * (ft_strlen(file_text) - i + 1));
	if (!buffer)
		return (ft_free_gnl(&file_text));
	i++;
	while (file_text[i])
		buffer[j++] = file_text[i++];
	if (j > 0)
		buffer[j] = '\0';
	else
	{
		free(buffer);
		return (ft_free_gnl(&file_text));
	}
	ft_free_gnl(&file_text);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*file_text[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	file_text[fd] = full_read(fd, file_text[fd]);
	if (!file_text[fd])
		return (NULL);
	line = line_read(file_text[fd]);
	if (!line)
		return (ft_free_gnl(&file_text[fd]));
	file_text[fd] = partial_read(file_text[fd]);
	return (line);
}
