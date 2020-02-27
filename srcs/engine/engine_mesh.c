/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_mesh.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:45:07 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		t_engine_draw_mesh(t_engine *p_engine)
{
	int i;

	i = 0;
	while (i < p_engine->visual_engine->camera_list->size)
	{
		t_physic_engine_draw_mesh(p_engine->physic_engine,
					t_camera_list_get(p_engine->visual_engine->camera_list, i));
		i++;
	}
}

void		t_engine_add_mesh(t_engine *engine, t_mesh p_mesh)
{
	t_physic_engine_add_mesh(engine->physic_engine, p_mesh);
}

void		t_engine_add_item(t_engine *engine, t_item p_item)
{
	t_physic_engine_add_item(engine->physic_engine, p_item);
}

t_mesh		*t_engine_get_mesh(t_engine *p_engine, int index)
{
	return (t_physic_engine_get_mesh(p_engine->physic_engine, index));
}

int			t_engine_return_mesh_len(t_engine *engine)
{
	return (engine->physic_engine->mesh_list->size);
}
