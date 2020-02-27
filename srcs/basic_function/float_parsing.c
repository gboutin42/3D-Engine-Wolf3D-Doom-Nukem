/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:42:37 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:42:38 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

float			get_short_float(float a, float b, float c)
{
	float			result;

	result = a;
	if (result > b)
		result = b;
	if (result > c)
		result = c;
	return (result);
}

float			get_big_float(float a, float b, float c)
{
	float			result;

	result = a;
	if (result < b)
		result = b;
	if (result < c)
		result = c;
	return (result);
}

float			float_min(float a, float b)
{
	if (a <= b)
		return (a);
	return (b);
}

float			float_max(float a, float b)
{
	if (a >= b)
		return (a);
	return (b);
}

float			ft_abs_float(float src)
{
	if (src < 0)
		return (-src);
	return (src);
}
