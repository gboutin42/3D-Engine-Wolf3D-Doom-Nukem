/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_mesh2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 11:49:52 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:00 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	test_move_axis_bis(t_mesh *mesh, float *force, t_vec4 axis,
														t_mesh *target)
{
	float	max;
	int		subdivision;
	int		i;
	float	delta;

	i = 0;
	subdivision = 20;
	delta = *force / subdivision;
	max = *force;
	*force = 0;
	while (i < subdivision
		&& mesh_intersect(mesh, target) == BOOL_FALSE)
	{
		i++;
		*force += delta;
		if (i == subdivision)
			*force = max;
		t_mesh_comp_next_vert_world(mesh, axis);
		if (mesh_intersect(mesh, target) == BOOL_TRUE)
			*force -= delta;
	}
}

int		can_move_bis(t_mesh *mesh, t_engine *engine)
{
	t_mesh	*target;
	int		i;

	i = 0;
	while (i < engine->physic_engine->mesh_list->size)
	{
		target = t_mesh_list_get(engine->physic_engine->mesh_list, i);
		if (mesh != target && target->bubble_radius + mesh->bubble_radius
			>= calc_dist_vec4(mesh->center, target->center)
			&& target->no_hitbox == 0)
		{
			test_move_axis_bis(mesh, &(mesh->force.y),
										new_vec4(0, 1, 0), target);
			test_move_axis_bis(mesh, &(mesh->force.x),
										new_vec4(1, 0, 0), target);
			test_move_axis_bis(mesh, &(mesh->force.z),
										new_vec4(0, 0, 1), target);
		}
		i++;
	}
	return (BOOL_TRUE);
}

void	cast_mesh(t_engine *engine, t_mesh *mesh_editing)
{
	t_camera	*cam;

	cam = t_camera_list_get(engine->visual_engine->camera_list, 0);
	mesh_editing->force = cam->forward;
	while (mesh_editing->force.x != 0 && mesh_editing->force.y != 0
										&& mesh_editing->force.z != 0)
	{
		if ((mesh_editing->pos.x - cam->pos.x > 10
							|| mesh_editing->pos.x - cam->pos.x < -10)
							|| (mesh_editing->pos.y - cam->pos.y > 10
							|| mesh_editing->pos.y - cam->pos.y < -10)
							|| (mesh_editing->pos.z - cam->pos.z > 10
							|| mesh_editing->pos.z - cam->pos.z < -10))
			mesh_editing->force = new_vec4(0.0, 0.0, 0.0);
		if (can_move_bis(mesh_editing, engine) == BOOL_TRUE)
			t_mesh_move(mesh_editing, mesh_editing->force);
	}
	mesh_editing->force = new_vec4(0.0, 0.0, 0.0);
}
