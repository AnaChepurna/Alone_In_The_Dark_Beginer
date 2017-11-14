/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 10:07:38 by exam              #+#    #+#             */
/*   Updated: 2017/11/14 10:34:00 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	tolower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 'a');
	return (c);
}

char	toupper(char c)
{
	return (c - 'a' + 'A');
}

void	count_letters(char *str, char c)
{
	int		count;

	count = 0;
	c = tolower(c);
	while (*str)
	{
		if (*str == c || *str == toupper(c))
		{
			count++;
			*str = '0';
		}
		str++;
	}
	printf("%i%c", count, c);
}

int		main(int v, char **c)
{
	int		i;
	int		start;

	start = 0;
	if (v == 2)
	{
		i = 0;
		while (c[1][i])
		{
			if ((c[1][i] >= 'a' && c[1][i] <= 'z') ||
					(c[1][i] >= 'A' && c[1][i] <= 'Z'))
			{
				if (start)
					printf(", ");
				count_letters(c[1], c[1][i]);
				start = 1;
			}
			i++;
		}
	}
	printf("\n");
}
