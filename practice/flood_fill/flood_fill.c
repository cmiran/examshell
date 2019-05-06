#include "t_point.h"

void	my_flood_fill(char **tab, t_point size, int x, int y, char oldcolor)
{
	if (x < 0 || y < 0)
		return ;
	else if (x >= size.x || y >= size.y)
		return ;
	else if (tab[y][x] != oldcolor)
		return ;
	else
		tab[y][x] = 'F';
	my_flood_fill(tab, size, x + 1, y, oldcolor);
	my_flood_fill(tab, size, x, y + 1, oldcolor);
	my_flood_fill(tab, size, x - 1, y, oldcolor);
	my_flood_fill(tab, size, x, y - 1, oldcolor);
}	

void	flood_fill(char **tab, t_point size, t_point begin)
{
	my_flood_fill(tab, size, begin.x, begin.y, tab[begin.y][begin.x]);
}
