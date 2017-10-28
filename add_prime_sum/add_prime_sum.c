/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 11:35:42 by exam              #+#    #+#             */
/*   Updated: 2017/10/24 12:28:29 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_atoi(char *str)
{
	int		result;
	int		i;

	result = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result);
}

void	ft_putnbr(int nb)
{
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

int		is_prime(int n)
{
	int		i;

	i = 2;
	while (i <= n / i)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int		main(int v, char **c)
{
	int		result;
	int		nbr;
	int		i;

	result = 0;
	if (v != 2)
	{
		ft_putchar('0');
		ft_putchar('\n');
	}
	else
	{
		nbr = ft_atoi(c[1]);
		i = 2;
		while (i <= nbr)
		{
			if (is_prime(i))
				result += i;
			i++;
		}
		ft_putnbr(result);
		ft_putchar('\n');
	}
}
