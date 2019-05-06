#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	char	c;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i])
		{
			c = argv[1][i];
			if (c >= 65 && c <= 90)
			{
				c = 65 + 90 - c;
				write(1, &c, 1);
			}
			else if (c >= 97 && c <= 122)
			{
				c = 97 + 122 - c;
				write(1, &c, 1);
			}
			else
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
