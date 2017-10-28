/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:35:24 by exam              #+#    #+#             */
/*   Updated: 2017/10/24 13:40:01 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	swap(int *a, int *b)
{
	int		buf;

	buf = *a;
	*a = *b;
	*b = buf;
}

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*step;

	step = lst;
	while (step->next)
	{
		if (!(*cmp)(step->data, step->next->data))
		{
			swap(&step->data, &step->next->data);
			step = lst;
		}
		else
			step = step->next;
	}
	return (lst);
}
