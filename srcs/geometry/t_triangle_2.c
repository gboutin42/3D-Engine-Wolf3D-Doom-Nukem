/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_triangle_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:28:17 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			t_triangle_similarity(t_triangle p_a, t_triangle p_b)
{
	t_vec4		a[3];
	t_vec4		b[3];
	int			result;
	int			i;
	int			j;

	a[0] = p_a.a;
	a[1] = p_a.b;
	a[2] = p_a.c;
	b[0] = p_b.a;
	b[1] = p_b.b;
	b[2] = p_b.c;
	result = 0;
	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			if (t_vec4_equal(a[i], b[j]) == BOOL_TRUE)
				result++;
	}
	return (result);
}

int			t_triangle_similarity_segment(t_triangle p_a, t_vec4 p_b,
																t_vec4 p_c)
{
	t_vec4		a[3];
	t_vec4		b[2];
	int			result;
	int			i;
	int			j;

	a[0] = p_a.a;
	a[1] = p_a.b;
	a[2] = p_a.c;
	b[0] = p_b;
	b[1] = p_c;
	result = 0;
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 2)
		{
			if (t_vec4_equal(a[i], b[j]) == BOOL_TRUE)
				result++;
			j++;
		}
		i++;
	}
	return (result);
}

float		maximum_dist_triangles(t_triangle tri1, t_triangle tri2)
{
	float	ret;
	int		i;
	float	dists[9];

	dists[0] = size_line(new_line(tri1.a, tri2.a));
	dists[0] = size_line(new_line(tri1.a, tri2.b));
	dists[0] = size_line(new_line(tri1.a, tri2.c));
	dists[0] = size_line(new_line(tri1.b, tri2.a));
	dists[0] = size_line(new_line(tri1.b, tri2.b));
	dists[0] = size_line(new_line(tri1.b, tri2.c));
	dists[0] = size_line(new_line(tri1.c, tri2.a));
	dists[0] = size_line(new_line(tri1.c, tri2.b));
	dists[0] = size_line(new_line(tri1.c, tri2.c));
	i = 0;
	ret = 600;
	while (i < 9)
	{
		if (ret > dists[i])
			ret = dists[i];
		i++;
	}
	return (ret);
}

int			triangles_intersection(t_triangle tri1, t_triangle tri2)
{
	t_line	seg;
	t_vec4	intersection;

	seg = new_line(tri1.a, tri1.b);
	if (intersect_triangle_by_segment(tri2, seg, &intersection) > 0)
		return (BOOL_TRUE);
	seg = new_line(tri1.b, tri1.c);
	if (intersect_triangle_by_segment(tri2, seg, &intersection) > 0)
		return (BOOL_TRUE);
	seg = new_line(tri1.a, tri1.c);
	if (intersect_triangle_by_segment(tri2, seg, &intersection) > 0)
		return (BOOL_TRUE);
	return (BOOL_FALSE);
}
