/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_mexlenoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 10:39:46 by exam              #+#    #+#             */
/*   Updated: 2017/11/14 12:12:01 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	putstr(char *str)
{
	if (!str)
		return ;
	while (*str)
		write(1, str++, 1);
}

int		ft_strlen(char *str)
{
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		strequ(char *s1, char *s2)
{
	while (*s2)
	{
		if (*s2 != *s1)
			return (0);
		s1++;
		s2++;
	}
	return (1);
}

char	*ft_strstr(char *str, char *needle)
{
	while (*str)
	{
		if (strequ(str, needle))
			return (needle);
		str++;
	}
	return (NULL);
}

void	ft_strlcpy(char *dst, char *src, int len)
{
	int		i;

	i = 0;
	while (src[i] && i < len - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*find_substring(char *s, char **cs)
{
	char	*tmp;
	int		slen;
	int		i;
	int		j;
	int		match;

	i = 0;
	slen = ft_strlen(s);
	tmp = NULL;
	while (i <= slen)
	{
		match = 1;
		if (tmp)
			free(tmp);
		if ((tmp = (char*)malloc(sizeof(char) * (slen - i + 1))))
		{
			ft_strlcpy(tmp, s, slen - i + 1);
			j = 0;
			while (cs[j])
			{
				if (!ft_strstr(cs[j], tmp))
					match = 0;
				j++;
			}
		}
		if (match)
		{
			return (tmp);
		}
		i++;
	}
	return (tmp);
}

int		main(int v, char **c)
{
	char	*sub;
	char	*tmp;
	char	*s;
	int 	i;

	if (v < 2)
	{
		putstr("\n");
		return (0);
	}
	s = c[1];
	i = 0;
	sub = NULL;
	while (s[i])
	{
		tmp = find_substring(s + i, c + 2);
		if (ft_strlen(sub) < ft_strlen(tmp))
		{
			if (sub)
				free(sub);
			sub = tmp;
		}
		else
			free(tmp);
		i++;
	}
	putstr(sub);
	putstr("\n");
}
