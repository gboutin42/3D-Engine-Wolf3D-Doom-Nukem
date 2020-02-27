/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_triangle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:03:34 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		intersect_triangle_by_segment2(float *f, t_vec4 *t_v,
							t_triangle p_triangle, t_vec4 *intersection)
{
	f[3] = dot_t_vec4(t_v[0], t_v[0]);
	f[4] = dot_t_vec4(t_v[0], t_v[1]);
	f[5] = dot_t_vec4(t_v[1], t_v[1]);
	t_v[5] = substract_vec4(*intersection, p_triangle.a);
	f[6] = dot_t_vec4(t_v[5], t_v[0]);
	f[7] = dot_t_vec4(t_v[5], t_v[1]);
	f[8] = f[4] * f[4] - f[3] * f[5];
	f[9] = (f[4] * f[7] - f[5] * f[6]) / f[8];
	if (f[9] < 0.0f || f[9] > 1.0f)
		return (0);
	f[10] = (f[4] * f[6] - f[3] * f[7]) / f[8];
	if (f[10] < 0.0f || (f[9] + f[10]) > 1.0f)
		return (0);
	return (1);
}

int		intersect_triangle_by_segment(t_triangle p_triangle, t_line line,
														t_vec4 *intersection)
{
	t_vec4	t_v[6];
	float	f[11];

	t_v[0] = substract_vec4(p_triangle.b, p_triangle.a);
	t_v[1] = substract_vec4(p_triangle.c, p_triangle.a);
	t_v[2] = cross_t_vec4(t_v[0], t_v[1]);
	if (t_v[2].x == 0.0 && t_v[2].y == 0.0 && t_v[2].z == 0.0)
		return (-1);
	t_v[3] = substract_vec4(line.b, line.a);
	t_v[4] = substract_vec4(line.a, p_triangle.a);
	f[1] = -dot_t_vec4(t_v[2], t_v[4]);
	f[2] = dot_t_vec4(t_v[2], t_v[3]);
	if (fabs(f[2]) < 0.00000001f)
	{
		if (f[1] == 0)
			return (2);
		else
			return (0);
	}
	f[0] = (f[1] / f[2]);
	if (f[0] < 0.0f || f[0] > 1.0f)
		return (0);
	*intersection = add_vec4(mult_vec4_by_float(t_v[3], f[0]), line.a);
	return (intersect_triangle_by_segment2(f, t_v, p_triangle, intersection));
}
