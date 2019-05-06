#include <unistd.h>

int	is_lower(char c)
{
	return (c >= 97 && c <= 122);
}

int	is_upper(char c)
{
	return (c >= 65 && c <= 90);
}

int	main(int argc, char **argv)
{
	int	i;
	char	c;
	char	*str;
	int	len;

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
			c = argv[1][i];
			if (is_upper(c))
			{
				len = c - 64;
				while (len--)
					write(1, &c, 1);
			}
			else if (is_lower(c))
			{
				len = c - 96;
				while (len--)
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
