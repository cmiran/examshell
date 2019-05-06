#include <stdio.h>

void	sort_in_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	int				tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j <= size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int		main(void)
{
	int tab[] = {5,77,4,98,475,21,4565,1,54,86,3};
	int	i;

	sort_in_tab(tab, 10);
	i = 0;
	while (tab[i])
		printf("%i\n", tab[i++]);
	return (0);
}
