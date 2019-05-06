#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int	i;
	int	j;
	int marker;

	if (ac >= 2)
	{
		i = 0;
		while (av[1][i] && (av[1][i] == ' ' || av[1][i] == '\t'))
			i++;
		if (av[1][i])
		{
			j = i;
			while (av[1][i] && av[1][i] != ' ' && av[1][i] != '\t')
				i++;
		}
		while (av[1][i])
		{
			while (av[1][i] && (av[1][i] == ' ' || av[1][i] == '\t'))
				i++;
			while (av[1][i] && av[1][i] != ' ' && av[1][i] != '\t')
			{
				marker = 1;
				write(1, &av[1][i++], 1);
			}
			if (av[1][i] || marker)
				write(1, " ", 1);
		}
		while (av[1][j] && av[1][j] != ' ' && av[1][j] != '\t')
			write(1, &av[1][j++], 1);
	}
	write(1, "\n", 1);
	return (0);
}
