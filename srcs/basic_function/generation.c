/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:43:26 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:43:27 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		generate_nbr(int min, int max)
{
	int	value;

	if (min < 0)
		max += -min;
	value = rand();
	value = value % max;
	value += min;
	return (value);
}

float	generate_float(float rmin, float rmax)
{
	return ((rand() / (float)RAND_MAX) * (rmax - rmin) + rmin);
}
