#include <unistd.h>

int	is_valid(char a, char b)
{
	return ((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}'));
}

int	brackets(char *str)
{
	int	i;
	int	j;
	int	loop[2048];

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
			loop[++j] = str[i];
		else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
			if (!is_valid(loop[j--], str[i]))
				return (0);
		i++;
	}
	return (!j);
}

int	main(int ac, char **av)
{
	int	i;

	if (ac == 1)
		write(1, "\n", 1);
	else
	{
		i = 1;
		while (i < ac)
		{
			if (brackets(av[i]))
				write(1, "OK\n", 3);
			else
				write(1, "Error\n", 6);
			i++;
		}
	}
	return (0);
}
