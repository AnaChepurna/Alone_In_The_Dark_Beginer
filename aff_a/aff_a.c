/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 10:06:13 by exam              #+#    #+#             */
/*   Updated: 2017/10/24 10:22:04 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	aff_a(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'a')
		{
			ft_putchar('a');
			ft_putchar('\n');
			return ;
		}
		i++;
	}
	ft_putchar('\n');
}

int		main(int v, char **c)
{
	if (v != 2)
	{
		ft_putchar('a');
		ft_putchar('\n');
	}
	else
	{
		aff_a(c[1]);
	}
}
