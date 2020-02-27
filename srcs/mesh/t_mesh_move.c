/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mesh_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 10:28:21 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	t_mesh_move(t_mesh *dest, t_vec4 delta)
{
	dest->pos = add_vec4(dest->pos, delta);
	dest->center = add_vec4(dest->center, delta);
}

void	t_mesh_look_at(t_mesh *mesh)
{
	t_vec4	zaxis;
	t_vec4	xaxis;
	t_vec4	yaxis;

	zaxis = normalize_t_vec4(new_vec4(\
		cos(degree_to_radius(mesh->angle.z)) \
			* sin(degree_to_radius(mesh->angle.y)),
		sin(degree_to_radius(mesh->angle.z)),
		cos(degree_to_radius(mesh->angle.z)) \
			* cos(degree_to_radius(mesh->angle.y))));
	xaxis = normalize_t_vec4(new_vec4(\
					sin(degree_to_radius(mesh->angle.y) - 3.14f / 2.0f),
					0, cos(degree_to_radius(mesh->angle.y) - 3.14f / 2.0f)));
	yaxis = normalize_t_vec4(cross_t_vec4(xaxis, zaxis));
	mesh->forward = zaxis;
	mesh->right = xaxis;
	mesh->up = inv_t_vec4(yaxis);
}

void	t_mesh_rotate_around_point(t_mesh *mesh, t_vec4 angle,
									t_vec4 center)
{
	t_matrix	translate;
	t_matrix	rotation;
	t_matrix	inv_translate;
	t_vec4		*target;
	int			i;

	translate = new_translation_matrix(substract_vec4(center,
																	mesh->pos));
	inv_translate = new_translation_matrix(inv_t_vec4(
							substract_vec4(center, mesh->pos)));
	rotation = create_rotation_matrix(angle.x, angle.y, angle.z);
	mesh->angle = add_vec4(mesh->angle, angle);
	t_mesh_look_at(mesh);
	i = -1;
	while (++i < mesh->vertices->size)
	{
		target = t_vec4_list_get(mesh->vertices, i);
		*target = mult_vec4_by_matrix(*target, inv_translate);
		*target = mult_vec4_by_matrix(*target, rotation);
		*target = mult_vec4_by_matrix(*target, translate);
	}
	t_mesh_compute_normals(mesh);
	t_mesh_compute_bubble_box(mesh);
}

void	t_mesh_rotate(t_mesh *mesh, t_vec4 delta_angle)
{
	t_matrix	rotation;
	t_vec4		*target;
	int			i;

	mesh->rotation = add_vec4(mesh->rotation,
			new_vec4(delta_angle.x, delta_angle.y, delta_angle.z));
	rotation = create_rotation_matrix(delta_angle.x, delta_angle.y,\
										delta_angle.z);
	mesh->angle = add_vec4(mesh->angle, delta_angle);
	t_mesh_look_at(mesh);
	i = -1;
	while (++i < mesh->vertices->size)
	{
		target = t_vec4_list_get(mesh->vertices, i);
		*target = mult_vec4_by_matrix(*target, rotation);
	}
	t_mesh_compute_normals(mesh);
	t_mesh_compute_bubble_box(mesh);
}
