/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physic_engine2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:45:37 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:45:38 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_physic_engine	new_physic_engine(void)
{
	t_physic_engine	result;

	result.gravity_force = new_vec4(0, -GRAVITY * 3, 0);
	result.mesh_list = initialize_t_mesh_list();
	result.item_list = initialize_t_item_list();
	return (result);
}

t_physic_engine	*initialize_t_physic_engine(void)
{
	t_physic_engine	*result;

	if (!(result = (t_physic_engine	*)ft_memalloc(sizeof(t_physic_engine))))
		return (NULL);
	*result = new_physic_engine();
	return (result);
}

void			delete_t_physic_engine(t_physic_engine dest)
{
	free_t_mesh_list(&dest.mesh_list);
	free_t_item_list(&dest.item_list);
}

void			free_t_physic_engine(t_physic_engine **dest)
{
	delete_t_physic_engine(**dest);
	ft_memdel((void**)dest);
}

void			t_physic_engine_apply_force(t_engine *engine)
{
	Uint32			actual_frame;
	static Uint32	last_frame = 0;
	int				i;
	float			time_passed;
	t_mesh			*mesh;

	actual_frame = SDL_GetTicks();
	time_passed = (actual_frame - last_frame) / 1000.0;
	i = 0;
	while (i < engine->physic_engine->mesh_list->size)
	{
		mesh = t_mesh_list_get(engine->physic_engine->mesh_list, i);
		if (mesh->kinetic > 0)
			mesh->force = add_vec4(mesh->force,
					mult_vec4_by_float(engine->physic_engine->gravity_force,
											mesh->kinetic * time_passed));
		if (mesh->force.x != 0 || mesh->force.y != 0 || mesh->force.z != 0)
			if (can_move(mesh, engine) == BOOL_TRUE)
				t_mesh_apply_force(mesh);
		i++;
	}
	last_frame = actual_frame;
}
