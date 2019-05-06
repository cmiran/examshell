#include "options.h"

int	check_options(char *str)
{
	int	i;

	i = 0;
	if (str[i] != '-')
	{
		write(1, "Invalid Option\n", 15);
		return (0);
	}
	while (str[++i])
	{
		if (str[i] == 'h')
		{
			write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
			return (0);
		}
		if (str[i] < 'a' || str[i] > 'z')
		{
			write(1, "Invalid Option\n", 15);
			return (0);
		}
	}
	return (1);
}

int	main(int ac, char **av)
{
	int		i;
	int		j;
	int		n;
	char	k;
	long	tmp;
	long	res;

	if (ac == 1)
		write(1, "options: abcdefghijklmnopqrstuvwxyz", 35);
	else
	{
		i = 1;
		tmp = 0;
		res = 0;
		while (av[i])
		{
			if (!check_options(av[i]))
				return (0);
			j = 1;
			while (av[i][j])
			{	
				tmp >>= (av[i][j] - 97);
				tmp |= 1; 
				tmp <<= (av[i][j] - 97);
				res |= tmp;
				j++;
			}
			i++;
		}
		n = 32;
		while (n--)
		{
			k = res >> n;
			k & 1 ? write(1, "1", 1) : write(1, "0", 1);
			if (n != 0 && n % 8 == 0)
				write (1, " ", 1);
		}
	}
	write(1 , "\n", 1);
	return (0);
}
