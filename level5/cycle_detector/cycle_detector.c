/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_detector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 10:11:38 by exam              #+#    #+#             */
/*   Updated: 2019/01/15 10:21:09 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list.h"

int					cycle_detector(const t_list *list)
{
	const t_list	*lst1;
	const t_list	*lst2;

	if (list == NULL)
		return (0);
	lst1 = list;
	lst2 = list;
	while (1)
	{
		lst1 = lst1->next;
		if (lst2->next != NULL)
			lst2 = lst2->next->next;
		else
			return (0);
		if (lst1 == NULL || lst2 == NULL)
			return (0);
		if (lst1 == lst2)
			return (1);
	}
}
