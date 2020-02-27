/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:42:45 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:42:46 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

float	ft_atof_bis(float a, int e)
{
	float	ret;

	while (e > 0)
	{
		a *= 10.0;
		e--;
	}
	while (e < 0)
	{
		a *= 0.1;
		e++;
	}
	ret = a;
	return (ret);
}

float	ft_atof(char *s)
{
	float	a;
	int		neg;
	int		e;
	int		c;

	a = 0.0;
	neg = 1;
	e = 0;
	if (s[0] == '-')
	{
		neg = -1;
		s++;
	}
	while ((c = *s++) != '\0' && is_digit(c))
		a = a * 10.0 + (c - '0');
	if (c == '.')
		while ((c = *s++) != '\0' && is_digit(c))
		{
			a = a * 10.0 + (c - '0');
			e = e - 1;
		}
	a = ft_atof_bis(a, e);
	return (a * neg);
}
