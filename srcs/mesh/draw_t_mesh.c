/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_t_mesh.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 10:58:58 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		init_points_uv(t_mesh *mesh, t_face face, t_vec4 *points_uv)
{
	points_uv[0] = t_vec4_list_at(mesh->uvs, face.index_uvs[0]);
	points_uv[1] = t_vec4_list_at(mesh->uvs, face.index_uvs[1]);
	points_uv[2] = t_vec4_list_at(mesh->uvs, face.index_uvs[2]);
}

void		init_points(t_mesh *mesh, t_face face, t_vec4 *points)
{
	points[0] = add_vec4(t_vec4_list_at(mesh->vertices,\
									face.idx_verts[0]), mesh->pos);
	points[1] = add_vec4(t_vec4_list_at(mesh->vertices,\
									face.idx_verts[1]), mesh->pos);
	points[2] = add_vec4(t_vec4_list_at(mesh->vertices,\
									face.idx_verts[2]), mesh->pos);
}

t_triangle	init_triangle_clipped(t_mesh *mesh, t_camera *p_cam, int j)
{
	t_triangle	triangle;

	triangle.a = apply_t_camera(&(p_cam->clipping_list[j + 0]),\
											&(p_cam->projection));
	triangle.b = apply_t_camera(&(p_cam->clipping_list[j + 1]),\
											&(p_cam->projection));
	triangle.c = apply_t_camera(&(p_cam->clipping_list[j + 2]),\
											&(p_cam->projection));
	if (mesh->texture != NULL)
	{
		t_triangle_list_push_back(&(p_cam->triangle_texture_list), triangle);
		triangle.a = p_cam->clipping_list_uv[j + 0];
		triangle.b = p_cam->clipping_list_uv[j + 1];
		triangle.c = p_cam->clipping_list_uv[j + 2];
	}
	return (triangle);
}

void		how_many_points_clipped(t_mesh *mesh, t_face face, t_camera *p_cam)
{
	t_vec4	points[3];
	t_vec4	points_uv[3];
	int		nb_clipped;
	float	result;

	init_points(mesh, face, &*points);
	if (mesh->texture != NULL)
		init_points_uv(mesh, face, &*points_uv);
	result = dot_t_vec4(face.normale, normalize_t_vec4(\
					substract_vec4(points[0], p_cam->pos)));
	if (result < 0)
	{
		points[0] = mult_vec4_by_matrix(points[0], (p_cam->view));
		points[1] = mult_vec4_by_matrix(points[1], (p_cam->view));
		points[2] = mult_vec4_by_matrix(points[2], (p_cam->view));
		if (mesh->texture != NULL)
			nb_clipped = clip_triangle_to_plane(p_cam, points, points_uv);
		else
			nb_clipped = clip_triangle_to_plane(p_cam, points, NULL);
		find_darkness(mesh, face, p_cam, nb_clipped);
	}
}

void		draw_t_mesh(t_camera *p_cam, t_mesh *mesh)
{
	int		i;
	t_face	face;

	i = -1;
	if (mesh->is_visible == BOOL_FALSE)
		return ;
	while (++i < mesh->faces->size)
	{
		face = t_face_list_at(mesh->faces, i);
		how_many_points_clipped(mesh, face, p_cam);
	}
}
