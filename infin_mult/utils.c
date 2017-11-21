/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 10:15:53 by exam              #+#    #+#             */
/*   Updated: 2017/11/21 13:14:25 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

size_t 		ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int	is_positive(char *s)
{
	if (s[0] != '-')
		return (1);
	return (0);
}

int			mult_sign(char **s1, char **s2)
{
	int		neg;

	neg = 0;
	if (!is_positive(*s1))
	{
		(*s1)++;
		neg++;
	}
	if (!is_positive(*s2))
	{
		(*s2)++;
		neg--;
	}
	return (neg);
}

int		get_number(char *str, size_t *len)
{
	if (*len == 0)
	{
		return (0);
	}
	else
	{
		(*len)--;
		return (str[*len] - '0');
	}
}

void	arr_free(char ***line)
{
	int		i;

	i = 0;
	while((*line)[i])
	{
		free((*line)[i]);
		i++;
	}
	free(*line);
	*line = NULL;
}
