#include <unistd.h>
#include <stdio.h>

int	ft_isupper(char c)
{
	return (c >= 65 && c <= 90);
}

int	ft_islower(char c)
{
	return (c >= 97 && c <= 122);
}

int	main(int argc, char **argv)
{
	int	i;
	char	c;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	else
	{
		i = 0;
		while (argv[1][i])
		{
			if (ft_isupper(argv[1][i]))
			{
				argv[1][i] < 78 ? (c = argv[1][i] + 13) : (c = argv[1][i] - 13);
				write(1, &c, 1);
			}
			else if (ft_islower(argv[1][i]))
			{
				argv[1][i] < 110 ? (c = argv[1][i] + 13) : (c = argv[1][i] - 13);
				write(1, &c, 1);
			}
			else
				write(1, &argv[1][i], 1);
			i++;
		}
		write(1, "\n", 1);
	}
	return (0);
}

