/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:42:12 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:42:14 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		is_mid(float min, float max, float value)
{
	float tmp;

	if (min > max)
	{
		tmp = min;
		min = max;
		max = tmp;
	}
	if (value >= min && value <= max)
		return (BOOL_TRUE);
	return (BOOL_FALSE);
}

float	clamp_float_value(float min, float value, float max)
{
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
}

int		clamp_int_value(int min, int value, int max)
{
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
}

float	inter_ratio(float a, float b, float c)
{
	if (b - a == 0)
		return (0);
	return ((c - a) / (b - a));
}

int		is_same_sign(float a, float b)
{
	if (a < 0)
	{
		if (b < 0)
			return (BOOL_TRUE);
		else
			return (BOOL_FALSE);
	}
	else
	{
		if (b >= 0)
			return (BOOL_TRUE);
		else
			return (BOOL_FALSE);
	}
}
