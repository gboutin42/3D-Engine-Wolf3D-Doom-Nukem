/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mesh_lighting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 11:03:37 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		apply_darkness_on_mesh_with_texture(t_mesh *mesh, t_camera *p_cam,\
								t_color darkness_color, t_triangle triangle)
{
	t_uv_list_push_back(&(p_cam->uv_list),\
						new_uv(triangle, mesh->texture));
	t_color_list_push_back(&(p_cam->darkness_list), darkness_color);
}

void		apply_darkness_on_mesh_without_texture(t_camera *p_cam, \
					t_face face, t_color darkness_color, t_triangle triangle)
{
	t_color_list_push_back(&(p_cam->color_list),\
					fuze_t_color(face.color, darkness_color));
	t_triangle_list_push_back(&(p_cam->triangle_color_list),\
													triangle);
}

void		find_darkness(t_mesh *mesh, t_face face, t_camera *cam,\
														int nb_clip)
{
	t_triangle	trgl;
	t_color		darkcol;
	float		darkness;
	int			j;

	darkness = (-dot_t_vec4(face.normale, cam->sun_direction) + 2)\
													/ (2 / (1 - 0.1));
	if (darkness > 1)
		darkness = 1;
	if (darkness < 0.1)
		darkness = 0.1;
	darkcol.r = darkness;
	darkcol.g = darkness;
	darkcol.b = darkness;
	darkcol.a = 0.4f;
	j = 0;
	while (j < nb_clip)
	{
		trgl = init_triangle_clipped(mesh, cam, j);
		if (mesh->texture == NULL)
			apply_darkness_on_mesh_without_texture(cam, face, darkcol, trgl);
		else
			apply_darkness_on_mesh_with_texture(mesh, cam, darkcol, trgl);
		j += 3;
	}
}
