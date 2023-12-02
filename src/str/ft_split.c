/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjulca <pjulca@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 00:04:31 by pjulca            #+#    #+#             */
/*   Updated: 2023/12/02 19:36:48 by pjulca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_words_count(char const *s, char c)
{
	int			words;
	int			word_counter;

	words = 0;
	word_counter = 0;
	while (s[word_counter])
	{
		if (s[word_counter] != c && s[word_counter])
		{
			words++;
			word_counter++;
			while (s[word_counter] != c && s[word_counter])
				word_counter++;
		}
		else
			word_counter++;
	}
	return (words);
}

static int	ft_word_len(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != c && s[i])
	{
		len++;
		i++;
	}
	return (len);
}

static void	ft_free_malloc(char **free_malloc)
{
	int	i;

	i = 0;
	while (free_malloc[i])
		free(free_malloc[i++]);
	free(free_malloc);
}

static char	**ft_split_allocator(char **split, char const *s, char c, int words)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = -1;
	while (++j < words)
	{
		while (s[i] == c)
			i++;
		len = ft_word_len(s, c, i);
		split[j] = ft_substr(s, i, len);
		if (!split[j])
		{
			ft_free_malloc(split);
			return (NULL);
		}
		i = i + len;
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**text_to_separate;
	int		words;

	words = ft_words_count(s, c);
	text_to_separate = (char **)malloc(sizeof(char *) * (words + 1));
	if (!text_to_separate)
		return (NULL);
	return (ft_split_allocator(text_to_separate, s, c, words));
}
