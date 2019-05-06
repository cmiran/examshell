#include <stdlib.h>
#include <stdio.h>

void	fprime(int nb)
{
	int	i;

	i = 1;
	if (nb == 1)
	{
		printf("1");
	}
	while (nb >= ++i)
	{
		if (nb % i == 0)
		{
			printf("%d", i);
			nb == i ? 0 : printf("*");
			nb /= i;
			i = 1;
		}
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		fprime(atoi(av[1]));
	}
	printf("\n");
	return (0);
}
