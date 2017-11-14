/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:15:59 by exam              #+#    #+#             */
/*   Updated: 2017/11/14 12:54:34 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		bufflen(unsigned int n, int base)
{
	int		i;

	if (n == 0)
		return (2);
	i = 1;
	while (n > 0)
	{
		i++;
		n = n / base;
	}
	return (i);
}

char	*fill_str(unsigned int n, int base, int sign)
{
	int		len;
	char	*res;
	char	*map;

	map = "0123456789ABCDEF";
	len = bufflen(n, base) + sign;
	if ((res = (char *)malloc(sizeof(char) * len)))
	{
		if (sign)
			res[0] = '-';
		res[--len] = '\0';
		while (--len - sign >= 0)
		{
			res[len] = map[n % base];
			n = n / base;
		}
	}
	return (res);
}

char	*ft_itoa_base(int value, int base)
{
	char			*res;
	int				sign;
	unsigned int	n;

	if (base < 2 || base > 16)
		return (NULL);
	sign = 0;
	if (base == 10 && value < 0)
		sign = 1;
	n = value > 0 ? value : -value;
	res = fill_str(n, base, sign);
	return (res);
}
