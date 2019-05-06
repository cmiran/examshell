#include <unistd.h>

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
			c = argv[1][i];
			if ((c >= 'A' && c <= 'Y') || (c >= 'a' && c <= 'y'))
			{
				c += 1;
				write(1, &c, 1);
			}
			else if (c == 'Z')
				write(1, "A", 1);
			else if (c == 'z')
				write(1, "a", 1);
			else
				write(1, &c, 1);
			i++;
		}
		write(1, "\n", 1);
	}
	return (0);
}
