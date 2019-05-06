#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "t_point.h"

void putc(char c)
{
	write(1, &c, 1);
}

char **tab_dup(char **tab, int h)
{
	int i;
	char **ret;

	i = 0;
	ret = malloc(sizeof(char*) * h);
	while (i < h)
	{
		ret[i] = strdup(tab[i]);
		i++;
	}
	return ret;
}

void print_tab(char **tab, t_point size)
{
	int x;
	int y;

	y = 0;
	while (y < size.y)
	{
		x = 0;
		while (x < size.x)
		{
			putc(tab[y][x]);
			putc(' ');
			x++;
		}
		putc('\n');
		y++;
	}
}

int main(void)
{
	t_point size = { 8, 7 };
	t_point begin = { 2, 4 };
	char *area[7];
	area[0] = "11111111";
	area[1] = "10001001";
	area[2] = "10010001";
	area[3] = "10110001";
	area[4] = "10010001";
	area[5] = "10001001";
	area[6] = "10000101";

	char **map = tab_dup(area, size.y);
	print_tab(map, size);
	flood_fill(map, size, begin);
	putc('\n');
	print_tab(map, size);
	return (0);
}
