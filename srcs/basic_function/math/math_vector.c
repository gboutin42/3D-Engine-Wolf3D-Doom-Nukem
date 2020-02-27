/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:42:05 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:42:07 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_vec4		cross_t_vec4(t_vec4 a, t_vec4 b)
{
	t_vec4	result;

	result = new_vec4(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z,
								a.x * b.y - a.y * b.x);
	return (result);
}

t_vec4		normalize_t_vec4(t_vec4 v)
{
	float	length_of_v;

	length_of_v = sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
	return (new_vec4(v.x / length_of_v, v.y
							/ length_of_v, v.z / length_of_v));
}

float		dot_t_vec4(t_vec4 a, t_vec4 b)
{
	float	result;

	result = a.x * b.x + a.y * b.y + a.z * b.z;
	return (result);
}

float		edge_t_vec4(t_vec4 a, t_vec4 b, t_vec4 c)
{
	float	result;

	result = (c.x - a.x) * (b.y - a.y) - (c.y - a.y) * (b.x - a.x);
	return (result);
}

float		calc_dist_vec4(t_vec4 a, t_vec4 b)
{
	return (sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y)
		+ (b.z - a.z) * (b.z - a.z)));
}
