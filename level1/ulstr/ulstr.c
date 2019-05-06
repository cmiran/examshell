/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 23:51:10 by maparmar          #+#    #+#             */
/*   Updated: 2019/02/25 23:51:15 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int ac, char **av)
{
	int		index;

	index = 0;
	if (ac == 2)
	{
		while (av[1][index] != '\0')
		{
			if (av[1][index] >= 'A' && av[1][index] <= 'Z')
				ft_putchar(av[1][index] - 'A' + 'a');
			else if (av[1][index] >= 'a' && av[1][index] <= 'z')
				ft_putchar(av[1][index] - 'a' + 'A');
			else
				ft_putchar(av[1][index]);
			index++;
		}
	}
	ft_putchar('\n');
	return (0);
}
