/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mesh_move2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 11:35:43 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	t_mesh_move_door_next(t_mesh *mesh, float tmp)
{
	if (tmp == 0.12f)
		mesh->door.state = 1;
	else
		mesh->door.state = 0;
	mesh->door.move = 0;
	mesh->door.tick = 0;
}

void	t_mesh_move_door(t_mesh *mesh, t_engine *engine)
{
	float	tmp;

	if (mesh->door.tick <= 5 && mesh->door.move == 1)
	{
		if (mesh->door.state == 0)
		{
			if (!Mix_Playing(1))
				Mix_PlayChannel(1, engine->sound_engine->sounds[12], 0);
			tmp = 0.12f;
		}
		else
		{
			if (!Mix_Playing(1))
				Mix_PlayChannel(1, engine->sound_engine->sounds[13], 0);
			tmp = -0.12f;
		}
		mesh->pos = add_vec4(mesh->pos, new_vec4(0.0, tmp, 0.0));
		mesh->center = add_vec4(mesh->center,
						new_vec4(0.0, tmp, 0.0));
		mesh->door.tick++;
		if (mesh->door.tick == 5)
			t_mesh_move_door_next(mesh, tmp);
	}
}

void	t_mesh_move_elevator_next(t_mesh *m, t_mesh *b, float tmp)
{
	if (tmp == 0.5f)
		m->door.state = 1;
	else
		m->door.state = 0;
	m->door.move = 0;
	m->door.tick = 0;
	if (t_mesh_on_mesh(b, m) == 1)
	{
		b->pos = add_vec4(b->pos, new_vec4(0.0, 0.05, 0.0));
		b->center = add_vec4(b->center, new_vec4(0.0, 0.05, 0.0));
	}
}

void	t_mesh_move_elevator(t_mesh *m, t_mesh *b)
{
	float	tmp;

	if (m->door.tick <= 17 && m->door.move == 1)
	{
		if (m->door.state == 0)
			tmp = 0.5f;
		else
			tmp = -0.5f;
		if (t_mesh_on_mesh(b, m) == 1)
		{
			b->pos = add_vec4(b->pos, new_vec4(0.0, tmp, 0.0));
			b->center = add_vec4(b->center, new_vec4(0.0, tmp, 0.0));
		}
		m->pos = add_vec4(m->pos, new_vec4(0.0, tmp, 0.0));
		m->center = add_vec4(m->center, new_vec4(0.0, tmp, 0.0));
		m->door.tick++;
		if (m->door.tick == 17)
			t_mesh_move_elevator_next(m, b, tmp);
	}
}
