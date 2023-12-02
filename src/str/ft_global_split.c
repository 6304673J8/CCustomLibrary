#include "libft.h"

static int	ft_isspace(char *str, int i)
{
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f' \
			|| str[i] == '\r' || str[i] == ' ')
		i++;
	return (i);
}

static int	w_len(char *str, int i)
{
	while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		i++;
	return (i);
}

static int	word_count(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	i = ft_isspace(str, i);
	while (str[i])
	{
		i = w_len(str, i);
		i = ft_isspace(str, i);
		count++;
	}
	return (count);
}

static char	*word_dupe(char *str)
{
	int	i;
	char *new_w;
	int	j;

	i = 0;
	j = 0;
	i = w_len(str, i);
	new_w = malloc(sizeof(char) * i + 1);
	new_w[i] = '\0';
	while (j < i)
	{
		new_w[j] = str[j];
		j++;
	}
	return (new_w);
}

static void	fill_words(char **array, char *str)
{
	int	i;
	int	tmp;

	tmp = 0;
	i = 0;
	tmp = ft_isspace(str, i);
	while (str[tmp])
	{
		array[i] = word_dupe(str + tmp);
		i++;
		tmp = w_len(str, tmp);
		tmp = ft_isspace(str, tmp);
	}
}

char    **ft_global_split(char *str)
{
	char	**array;
	int		tmp;

	tmp = word_count(str);
	array = malloc(sizeof(char *) * tmp + 1);
	array[tmp] = 0;
	fill_words(array, str);
	return (array);
}

/*
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int ac, char **av)
{
	char	**str;
	int		i;

	i = 0;
	if (ac == 2)
	{
		str = ft_global_split(av[1]);
		while (str[i])
		{
			printf("%s", str[i]);
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}*/
