/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_geo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:41:54 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:41:56 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			same_side(t_vec4 p1, t_vec4 p2, t_vec4 a, t_vec4 b)
{
	t_vec4	cp1;
	t_vec4	cp2;
	t_vec4	b_a;

	b_a = substract_vec4(b, a);
	cp1 = cross_t_vec4(b_a, substract_vec4(p1, a));
	cp2 = cross_t_vec4(b_a, substract_vec4(p2, a));
	if (dot_t_vec4(cp1, cp2) >= 0)
		return (BOOL_TRUE);
	else
		return (BOOL_FALSE);
}

t_vec4		inter_plane_line(t_vec4 p_normal, t_vec4 p_center,
											t_vec4 start, t_vec4 end)
{
	t_vec4	intersection;
	t_vec4	basic_line;
	t_vec4	normalized_plane;
	float	tabf[4];

	normalized_plane = normalize_t_vec4(p_normal);
	tabf[0] = dot_t_vec4(normalized_plane, p_center);
	tabf[1] = dot_t_vec4(start, normalized_plane);
	tabf[2] = dot_t_vec4(end, normalized_plane);
	tabf[3] = (tabf[0] - tabf[1]) / (tabf[2] - tabf[1]);
	basic_line = substract_vec4(end, start);
	intersection = mult_vec4_by_float(basic_line, tabf[3]);
	return (add_vec4(start, intersection));
}

int			is_point_on_line(t_vec4 a, t_vec4 b, t_vec4 c)
{
	float dist_tot;
	float dist_part_one;
	float dist_part_two;

	dist_tot = calc_dist_vec4(a, b);
	dist_part_one = calc_dist_vec4(a, c);
	dist_part_two = calc_dist_vec4(c, b);
	if (dist_tot == dist_part_one + dist_part_two)
		return (BOOL_TRUE);
	return (BOOL_FALSE);
}

float		dist_plane(t_vec4 p_normal, t_vec4 p_center,
														t_vec4 p_point)
{
	t_vec4	normalized_plane;
	float	result;

	normalized_plane = normalize_t_vec4(p_normal);
	result = p_point.x * normalized_plane.x
			+ p_point.y * normalized_plane.y
			+ p_point.z * normalized_plane.z
			- dot_t_vec4(normalized_plane, p_center);
	return (result);
}

t_vec4		inter_vec4_line(float ratio_x, float ratio_y,
													t_vec4 ua, t_vec4 ub)
{
	t_vec4	result;

	result.x = ((ub.x - ua.x) * ratio_x) + ua.x;
	result.y = ((ub.y - ua.y) * ratio_y) + ua.y;
	result.z = 0;
	return (result);
}
