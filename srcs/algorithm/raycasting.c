/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:11:51 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_mesh	*cast_ray_next(t_vec4 pos, t_vec4 direction, t_mesh *mesh)
{
	int			k;
	t_line		line;
	t_vec4		intersection;

	k = -1;
	line = new_line(pos, add_vec4(pos, direction));
	while (++k < mesh->faces->size)
	{
		if ((mesh->no_hitbox == 0 || mesh->is_visible == 1)
		&& intersect_triangle_by_segment(compose_t_triangle_from_t_mesh(mesh,
			t_face_list_get(mesh->faces, k)->idx_verts), line,
				&intersection) == BOOL_TRUE)
			return (mesh);
	}
	return (NULL);
}

t_mesh	*cast_ray(t_engine *engine, t_vec4 pos, t_vec4 direction,
																char *shooter)
{
	int			i;
	int			j;
	t_mesh		*mesh;

	i = -1;
	direction = divide_vec4_by_float(direction, 10);
	while (++i < 100)
	{
		j = -1;
		while (++j < t_engine_return_mesh_len(engine))
		{
			mesh = t_engine_get_mesh(engine, j);
			if (ft_strcmp(mesh->name, shooter) != 0)
			{
				mesh = cast_ray_next(pos, direction, mesh);
				if (mesh != NULL)
					return (mesh);
			}
		}
		pos = add_vec4(pos, direction);
	}
	return (NULL);
}
