/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 10:51:39 by exam              #+#    #+#             */
/*   Updated: 2017/10/24 11:27:52 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		check_doubles(char c, char *str, int n)
{
	int		i;

	i = 0;
	while (i < n && str[i])
	{
		if (c == str[i])
			return (0);
		i++;
	}
	return (1);
}

void	first_str_uni(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (check_doubles(str[i], str, i))
			ft_putchar(str[i]);
		i++;
	}
}

void	second_str_uni(char *str1, char *str2)
{
	int		i;

	i = 0;
	while (str2[i])
	{
		if (check_doubles(str2[i], str1, 200) & 
				check_doubles(str2[i], str2, i))
			ft_putchar(str2[i]);
		i++;
	}
	ft_putchar('\n');
}

int		main(int v, char **c)
{
	if (v != 3)
		ft_putchar('\n');
	else
	{
		first_str_uni(c[1]);
		second_str_uni(c[1], c[2]);
	}
}
