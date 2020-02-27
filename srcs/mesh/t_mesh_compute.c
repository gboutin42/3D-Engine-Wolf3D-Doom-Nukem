/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mesh_compute.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 10:32:34 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	t_mesh_compute_normals(t_mesh *mesh)
{
	t_face	*face;
	t_vec4	a;
	t_vec4	b;
	t_vec4	c;
	int		i;

	clean_t_vec4_list(mesh->normales);
	i = -1;
	while (++i < mesh->faces->size)
	{
		face = t_face_list_get(mesh->faces, i);
		a = t_vec4_list_at(mesh->vertices, face->idx_verts[0]);
		b = substract_vec4(t_vec4_list_at(mesh->vertices,
											face->idx_verts[1]), a);
		c = substract_vec4(t_vec4_list_at(mesh->vertices,
											face->idx_verts[2]), a);
		face->normale = normalize_t_vec4(cross_t_vec4(b, c));
		t_vec4_list_push_back(mesh->normales, new_vec4(0, 0, 0));
		t_vec4_list_push_back(mesh->normales, face->normale);
	}
}

void	t_mesh_compute_bubble_box(t_mesh *mesh)
{
	int		i;
	float	tmp;
	t_vec4	total;

	total = new_vec4(0.0, 0.0, 0.0);
	i = -1;
	while (++i < mesh->vertices->size)
		total = add_vec4(total,
					t_vec4_list_at(mesh->vertices, i));
	if (i > 0)
		total = divide_vec4_by_float(total, (float)(i));
	mesh->center = add_vec4(total, mesh->pos);
	i = -1;
	while (++i < mesh->vertices->size)
	{
		tmp = calc_dist_vec4(total,
					t_vec4_list_at(mesh->vertices, i));
		if (mesh->bubble_radius < tmp)
			mesh->bubble_radius = tmp;
	}
}

void	t_mesh_compute_vertices_in_world(t_mesh *dest)
{
	int		i;

	i = -1;
	clean_t_vec4_list(dest->vertices_in_world);
	while (++i < dest->vertices->size)
		t_vec4_list_push_back(dest->vertices_in_world,
		add_vec4(t_vec4_list_at(dest->vertices, i),
													dest->pos));
}

void	t_mesh_comp_next_vert_world(t_mesh *dest, t_vec4 axis)
{
	t_vec4	next_pos;
	int		i;

	i = -1;
	clean_t_vec4_list(dest->next_vert);
	next_pos = add_vec4(dest->pos,
				mult_2_vec4(dest->force, axis));
	while (++i < dest->vertices->size)
		t_vec4_list_push_back(dest->next_vert,
		add_vec4(t_vec4_list_at(dest->vertices, i), next_pos));
}

int		t_mesh_on_mesh(t_mesh *body, t_mesh *target)
{
	float	x_max;
	float	z_max;
	float	x_min;
	float	z_min;

	x_min = target->pos.x + ((target->center.x - target->pos.x) * 2);
	z_min = target->pos.z + ((target->center.z - target->pos.z) * 2);
	if (target->pos.x > x_min)
		x_max = target->pos.x;
	else
	{
		x_max = x_min;
		x_min = target->pos.x;
	}
	if (target->pos.z > z_min)
		z_max = target->pos.z;
	else
	{
		z_max = z_min;
		z_min = target->pos.z;
	}
	if ((body->pos.x + 0.3 >= x_min && body->pos.x <= x_max)
		&& (body->pos.z + 0.3 >= z_min && body->pos.z <= z_max))
		return (1);
	return (0);
}
