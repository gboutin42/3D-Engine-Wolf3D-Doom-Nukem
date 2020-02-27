/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physic_engine3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:45:47 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:45:48 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			t_physic_engine_draw_mesh(t_physic_engine *p_physic_engine,
											t_camera *p_cam)
{
	int			i;

	i = 0;
	while (i < p_physic_engine->mesh_list->size)
	{
		draw_t_mesh(p_cam, t_mesh_list_get(p_physic_engine->mesh_list, i));
		i++;
	}
}

void			t_physic_engine_add_mesh(t_physic_engine *physic_engine,
											t_mesh p_mesh)
{
	t_mesh_list_push_back(physic_engine->mesh_list, p_mesh);
}

void			t_physic_engine_add_item(t_physic_engine *physic_engine,
											t_item p_item)
{
	t_item_list_push_back(physic_engine->item_list, p_item);
}

t_mesh			*t_physic_engine_get_mesh(t_physic_engine *physic_engine,
											int index)
{
	return (t_mesh_list_get(physic_engine->mesh_list, index));
}

void			t_p_engine_comp_vert_world(t_physic_engine *physic_engine)
{
	int		i;

	i = 0;
	while (i < physic_engine->mesh_list->size)
	{
		t_mesh_compute_vertices_in_world(
				t_mesh_list_get(physic_engine->mesh_list, i));
		i++;
	}
}
