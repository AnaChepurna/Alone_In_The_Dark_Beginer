/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 10:05:27 by exam              #+#    #+#             */
/*   Updated: 2017/11/21 13:19:26 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H

#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(char *s);
int		mult_sign(char **s1, char **s2);
int		get_number(char *str, size_t *len);
void	arr_free(char ***line);
void	ft_putendl(char *s);

#endif
