/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_triangle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:31:26 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_triangle	new_triangle(t_vec4 p_a, t_vec4 p_b, t_vec4 p_c)
{
	t_triangle	result;

	result.a = p_a;
	result.b = p_b;
	result.c = p_c;
	return (result);
}

t_triangle	*initialize_t_triangle(t_vec4 p_a, t_vec4 p_b, t_vec4 p_c)
{
	t_triangle	*result;

	if (!(result = (t_triangle *)ft_memalloc(sizeof(t_triangle))))
		error_exit(-31, "Can't ft_memalloc a t_triangle");
	*result = new_triangle(p_a, p_b, p_c);
	return (result);
}

void		sort_t_triangles(t_triangle *a, t_triangle *b)
{
	t_triangle	tmp;

	sort_t_triangle_points(a);
	sort_t_triangle_points(b);
	if (t_triangle_is_bigger(*a, *b) == BOOL_FALSE)
	{
		tmp = *a;
		*a = *b;
		*b = tmp;
	}
}

void		sort_t_triangle_points(t_triangle *p_triangle)
{
	if (p_triangle->a.y > p_triangle->b.y || (p_triangle->a.y == p_triangle->b.y
										&& p_triangle->a.x > p_triangle->b.x))
		swap_t_vec4(&(p_triangle->a), &(p_triangle->b));
	if (p_triangle->b.y > p_triangle->c.y || (p_triangle->b.y == p_triangle->c.y
										&& p_triangle->b.x > p_triangle->c.x))
		swap_t_vec4(&(p_triangle->b), &(p_triangle->c));
	if (p_triangle->a.y > p_triangle->b.y || (p_triangle->a.y == p_triangle->b.y
										&& p_triangle->a.x > p_triangle->b.x))
		swap_t_vec4(&(p_triangle->a), &(p_triangle->b));
}

t_vec4		triangle_center(t_triangle tri)
{
	t_vec4	ret;

	ret = new_vec4((tri.a.x + tri.b.x + tri.c.x) / 3,
					(tri.a.y + tri.b.y + tri.c.y) / 3,
					(tri.a.z + tri.b.z + tri.c.z) / 3);
	return (ret);
}
