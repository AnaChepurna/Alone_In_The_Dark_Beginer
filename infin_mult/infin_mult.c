/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_mult.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 10:07:16 by exam              #+#    #+#             */
/*   Updated: 2017/11/21 13:22:24 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char    *add_lines(char **line, size_t len)
{
	int     extra;
	int     number;
	size_t  i;
	char    *res;
	
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[len] = '\0';
	extra = 0;
	while (len-- > 0)
	{
		number = extra;
		i = 0;
		while (line[i])
			number += line[i++][len] - '0';
		extra = number / 10;
		res[len] = number % 10 + '0';
	}
	return (res);
}

char	*mult_line(char *str, int c, size_t size, int ten)
{
	char	*res;
	int		extra;
	int		number;
	size_t	str_len;

	if ((res = (char *)malloc(sizeof(char) * (size + 1))))
	{
		res[size] = '\0';
		while (ten-- > 0)
			res[--size] = '0';
		extra = 0;
		str_len = ft_strlen(str);
		while (size > 0)
		{
			number = c * get_number(str, &str_len) + extra;
			extra = number / 10;
			number = number % 10;
			res[--size] = number + '0';
		}
	}
	return (res);
}

char	**mult(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	**res;
	size_t		i;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if ((res = (char **)malloc(sizeof(char *) * (s2_len + 1))))
	{
		i = 0;
		while (i < s2_len)
		{
			res[i] = mult_line(s1, s2[s2_len - i - 1] - '0', s2_len + s1_len + 1, i);
			i++;
		}
		res[i] = NULL;
	}
	return (res);
}

char	*perform(char *s1, char *s2)
{
	int		neg;
	char	**lines;
	char	*res;
	size_t	len;
	size_t	i;

	neg = mult_sign(&s1, &s2);
	lines = mult(s1, s2);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = add_lines(lines, len);
	arr_free(&lines);
	i = 0;
	while(res[i] == '0' && i < len)
		i++;
	if (i == len)
		res = res + i - 1;
	else if (neg)
	{
		res[i - 1] = '-';
		res = res + i - 1;
	}
	else
		res = res + i;
	return (res);
}

int		main(int v, char **c)
{
	if (v == 3)
		ft_putendl(perform(c[1], c[2]));
}
