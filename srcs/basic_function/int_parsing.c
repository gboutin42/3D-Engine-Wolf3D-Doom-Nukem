/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:43:33 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:43:35 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_atoi(const char *str)
{
	int			i;
	long long	number;
	int			neg;

	i = 0;
	number = 0;
	neg = 1;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\t' ||
			str[i] == '\n' || str[i] == '\r' || str[i] == '\v')
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + (str[i] - '0');
		i++;
	}
	return (number * neg);
}

int		get_short(int a, int b, int c)
{
	int			result;

	result = a;
	if (result > b)
		result = b;
	if (result > c)
		result = c;
	return (result);
}

int		get_big(int a, int b, int c)
{
	int			result;

	result = a;
	if (result < b)
		result = b;
	if (result < c)
		result = c;
	return (result);
}

int		min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

int		max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}
