/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primitive_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 11:14:29 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		t_mesh_init_uv_point_primitive_plane(t_mesh *result)
{
	t_mesh_add_uv(result, new_vec4(0.0f, 0.0f, 0.0f));
	t_mesh_add_uv(result, new_vec4(1.0f, 0.0f, 0.0f));
	t_mesh_add_uv(result, new_vec4(0.0f, 1.0f, 0.0f));
	t_mesh_add_uv(result, new_vec4(1.0f, 1.0f, 0.0f));
}

t_mesh		create_plane(t_vec4 pos, t_vec4 size,
											char *texture_path, float gravity)
{
	t_mesh	result;
	t_face	tmp_face;

	result = new_mesh(pos);
	result.primitive = 0;
	result.size = new_vec4(size.x, size.y, size.z);
	activate_gravity(&result, gravity);
	t_mesh_add_point(&result, new_vec4(-size.x / 2, 0.0, -size.z / 2));
	t_mesh_add_point(&result, new_vec4(size.x / 2, 0.0, -size.z / 2));
	t_mesh_add_point(&result, new_vec4(size.x / 2, 0.0, size.z / 2));
	t_mesh_add_point(&result, new_vec4(-size.x / 2, 0.0, size.z / 2));
	t_mesh_init_uv_point_primitive_plane(&result);
	tmp_face = new_face();
	set_t_face_vertices(&tmp_face, 2, 1, 3);
	set_t_face_uvs(&tmp_face, 3, 2, 1);
	t_mesh_add_face(&result, tmp_face);
	tmp_face = new_face();
	set_t_face_vertices(&tmp_face, 0, 3, 1);
	set_t_face_uvs(&tmp_face, 0, 1, 2);
	t_mesh_add_face(&result, tmp_face);
	t_mesh_compute_normals(&result);
	t_mesh_compute_bubble_box(&result);
	if (texture_path != NULL)
		result.texture = png_load(texture_path);
	return (result);
}
