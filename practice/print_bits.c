#include <unistd.h>

int	main(int argc, char **argv)
{
	char	k;
	int	len;

	if (argc == 2)
	{
		len = 8;
		while (len--)
		{
			k = argv[1][0] >> len;
			if (k & 1)
				write(1, 0, 1);
			else
				write(1, 0, 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
