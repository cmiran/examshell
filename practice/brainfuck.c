#include <unistd.h>

void	brainfuck(char *str)
{
	int	tab[2048] = {0};
	int	*ptr;
	int	loop;

	ptr = tab;
	while (*str)
	{
		if (*str == '>')
			ptr++;
		else if (*str == '<')
			ptr--;
		else if (*str == '+')
			(*ptr)++;
		else if (*str == '-')
			(*ptr)--;
		else if (*str == '.')
			write(1, ptr, 1);
		else if (*str == '[' && *ptr == 0)
		{
			loop = 1;
			while (loop)
			{
				str++;
				if (*str == '[')
					loop++;
				else if (*str == ']')
					loop--;
			}
		}
		else if (*str == ']' && *ptr != 0)
		{
			loop = 1;
			while (loop)
			{
				str--;
				if (*str == '[')
					loop--;
				else if (*str == ']')
					loop++;
			}
		}
		str++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		brainfuck(av[1]);
	return (0);
}
