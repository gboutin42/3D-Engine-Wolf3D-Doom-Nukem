/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_enemy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:50:38 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/19 15:59:50 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		enemy_look_next(t_camera *cam, t_mesh *target)
{
	float		tmp;

	cam->pos = add_vec4(cam->body->pos, new_vec4(0.15, 0.45, -0.15));
	t_camera_look_at_point(cam, target->center);
	tmp = (cam->yaw - cam->body->angle.x);
	if (tmp > cam->body->angle.x + 1.0f || tmp < cam->body->angle.x - 1.0f)
	{
		t_mesh_rotate_around_point(cam->body,
			new_vec4(0.0, tmp, 0.0), cam->body->center);
		cam->body->angle.x = cam->yaw;
	}
}

void		enemy_look(t_engine *engine)
{
	int			i;
	t_camera	*cam;
	t_mesh		*target;

	i = -1;
	while (++i < engine->physic_engine->mesh_list->size
	&& (target = t_mesh_list_get(engine->physic_engine->mesh_list, i)))
		if (ft_strcmp(target->name, "Player") == 0)
			break ;
	i = -1;
	while (++i < engine->visual_engine->camera_list->size)
	{
		cam = t_camera_list_get(engine->visual_engine->camera_list, i);
		if (cam->body != NULL && (ft_strcmp(cam->body->name, "Enemy") == 0 ||
			ft_strcmp(cam->body->name, "Enemy_boss") == 0))
			enemy_look_next(cam, target);
	}
}

void		enemy_shoot(t_engine *engine)
{
	int			i;
	t_mesh		*target;
	t_mesh		*mesh;

	i = -1;
	while (++i < engine->physic_engine->mesh_list->size)
	{
		target = t_mesh_list_get(engine->physic_engine->mesh_list, i);
		if (ft_strcmp(target->name, "Enemy") == 0)
		{
			mesh = cast_ray(engine, target->camera->pos,
				target->camera->forward, "Enemy");
			if (mesh != NULL && engine->tick - target->tick == 2 &&
				ft_strcmp(mesh->name, "Player") == 0)
			{
				player_take_dmg(engine, 5);
				target->tick = -5;
			}
			else if (mesh != NULL && engine->tick - target->tick > 3
				&& ft_strcmp(mesh->name, "Player") == 0)
				target->tick = engine->tick;
			else if (mesh == NULL || ft_strcmp(mesh->name, "Player") != 0)
				target->tick = -5;
		}
	}
}

void		enemy_move(t_engine *engine)
{
	int			i;
	t_mesh		*mesh;
	t_mesh		*target;

	i = 0;
	while (i < engine->physic_engine->mesh_list->size)
	{
		mesh = t_mesh_list_get(engine->physic_engine->mesh_list, i);
		if (ft_strcmp(mesh->name, "Enemy") == 0)
		{
			target = cast_ray(engine, mesh->camera->pos,
				mesh->camera->forward, "Enemy");
			if (target != NULL && ft_strcmp(target->name, "Player") == 0)
			{
				mesh->force = divide_vec4_by_float(mesh->camera->forward,
								25);
				mesh->force.y = 0;
				if (can_move(mesh, engine) == BOOL_TRUE)
					t_mesh_move(mesh, mesh->force);
			}
			else
				mesh->force = new_vec4(0.0, 0.0, 0.0);
		}
		i++;
	}
}
