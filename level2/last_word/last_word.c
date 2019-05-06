/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 22:36:21 by maparmar          #+#    #+#             */
/*   Updated: 2019/03/24 22:37:00 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	fn_word(char *str, int *i)
{
	while (str[*i] != ' ' && str[*i] != '\t' && str[*i])
		(*i) += 1;
}

void	print_word(char *str, int start, int end)
{
	int		i;
	int		c;

	i = start;
	while (str[i] && str[i] != ' ' && str[i] != '\t' && end--)
		write(1, &str[i++], 1);
}

int		main(int argc, char **argv)
{
	int		i;
	int		start;
	int		end;

	if (argc == 2)
	{
		i = 0;
		start = 0;
		end = 0;
		while ((argv[1][i] == ' ' || argv[1][i] == '\t') && argv[1][i])
			i += 1;
		while (argv[1][i])
		{
			start = i;
			fn_word(argv[1], &i);
			end = i;
			while (argv[1][i] && (argv[1][i] == ' ' || argv[1][i] == '\t'))
				i += 1;
			if (!argv[1][i])
				print_word(argv[1], start, end);
		}
	}
	write(1, "\n", 1);
	return (0);
}
