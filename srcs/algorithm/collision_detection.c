/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_detection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:15:31 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_triangle		is_triangle_target(t_face *face, t_mesh *target)
{
	t_triangle	result;

	result.a = t_vec4_list_at(target->vertices_in_world,
													face->idx_verts[0]);
	result.b = t_vec4_list_at(target->vertices_in_world,
													face->idx_verts[1]);
	result.c = t_vec4_list_at(target->vertices_in_world,
													face->idx_verts[2]);
	return (result);
}

int				sat_test(t_face *face, t_mesh *target, t_mesh *mesh)
{
	t_triangle	comp;
	t_triangle	tar;
	t_face		*cur;
	int			i;
	float		dist;

	tar = is_triangle_target(face, target);
	dist = fabs(calc_dist_vec4(mesh->center, triangle_center(tar)));
	if (dist < fabs(calc_dist_vec4(tar.a, tar.b)) || dist < fabs(calc_dist_vec4(
		tar.a, tar.c)) || dist < fabs(calc_dist_vec4(tar.c, tar.b)))
	{
		i = -1;
		while (++i < mesh->faces->size)
		{
			if (mesh->next_vert->size == 0)
				break ;
			cur = t_face_list_get(mesh->faces, i);
			comp.a = t_vec4_list_at(mesh->next_vert, cur->idx_verts[0]);
			comp.b = t_vec4_list_at(mesh->next_vert, cur->idx_verts[1]);
			comp.c = t_vec4_list_at(mesh->next_vert, cur->idx_verts[2]);
			if (triangles_intersection(comp, tar))
				return (BOOL_TRUE);
		}
	}
	return (BOOL_FALSE);
}

int				mesh_intersect(t_mesh *mesh_compared, t_mesh *target)
{
	int		i;

	i = -1;
	while (++i < target->faces->size)
		if (sat_test(t_face_list_get(target->faces, i), target, mesh_compared))
			return (BOOL_TRUE);
	return (BOOL_FALSE);
}
