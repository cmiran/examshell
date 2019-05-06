#include <stdlib.h>
#include <stdio.h>

int		count_letters(char *str)
{
	int		i;
	int		res;
	int		tmp;

	i = 0;
	res = 0;
	while (str[i])
	{
		tmp = 0;
		while (str[i] && str[i] != '\n' && str[i] != ' ' && str[i] != '\t')
		{
			tmp++;
			i++;
		}
		if (res < tmp)
			res = tmp;
		if (str[i])
			i++;
	}
	return (res);
}

int		count_words(char *str)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] == '\n' || str[i] == ' ' || str[i] == '\t')
			i++;
		else
		{
			res++;
			while (str[i] && str[i] != '\n' && str[i] != ' ' && str[i] != '\t')
				i++;
		}
	}
	return (res);
}

char	**ft_split(char *str)
{
	char	**tab;
	int		words;
	int		letters;
	int		i;
	int		j;
	int		k;

	words = count_words(str);
	letters = count_letters(str);
	if (!(tab = (char **)malloc(sizeof(char *) * words + 1)))
		return (0);
	i = 0;
	j = 0;
	while (str[i])
	{
		k = 0;
		if (str[i] == '\n' || str[i] == ' ' || str[i] == '\t')
			i++;
		else
		{
			if (!(tab[j] = (char *)malloc(sizeof(char) * letters + 1)))
				return (0);
			while (str[i] && str[i] != '\n' && str[i] != ' ' && str[i] != '\t')
				tab[j][k++] = str[i++];
			tab[j][k] = '\0';
			j++;
		}
	}
	tab[j] = NULL;
	return (tab);
}

int		main(int ac, char **av)
{
	char	**tab;
	int		i;

	if (ac == 2)
	{
		tab = ft_split(av[1]);
		i = 0;
		while (tab[i])
			i++;
		while (i-- > 0)
		{
			printf("%s", tab[i]);
			if (i > 0)
				printf(" ");
		}	
	}
	printf("\n");
	return (0);
}
