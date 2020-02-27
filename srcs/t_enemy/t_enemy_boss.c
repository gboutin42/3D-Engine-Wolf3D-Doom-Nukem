/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_enemy_boss.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:50:32 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/19 15:59:20 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			enemy_boss_shoot(t_engine *engine)
{
	int			i;
	t_mesh		*target;
	t_mesh		*mesh;

	i = -1;
	while (++i < engine->physic_engine->mesh_list->size)
	{
		target = t_mesh_list_get(engine->physic_engine->mesh_list, i);
		if (ft_strcmp(target->name, "Enemy_boss") == 0)
		{
			if (target->tick == 0)
				target->tick = engine->tick;
			if (engine->tick - target->tick == 6)
			{
				mesh = cast_ray(engine, target->camera->pos,
						target->camera->forward, "Enemy_boss");
				if (mesh != NULL && ft_strcmp(mesh->name, "Player") == 0)
					player_take_dmg(engine, 30);
				else if (mesh != NULL && mesh->hp != -1)
					destroy_mesh(mesh);
				target->tick = engine->tick;
			}
		}
	}
}

t_vec4			spawn_mine(t_vec4 pos)
{
	t_vec4	ret;

	ret = new_vec4(generate_float(pos.x - 4.5, pos.x + 4.5), pos.y,
			generate_float(pos.z - 4.5, pos.z + 4.5));
	if (ret.x > -1.5f && ret.x < 1.5f)
	{
		if (ret.x < 0)
			ret.x -= 1.0f;
		else
			ret.x += 1.0f;
	}
	if (ret.z > -1.5f && ret.z < 1.5f)
	{
		if (ret.z < 0)
			ret.z -= 1.0f;
		else
			ret.z += 1.0f;
	}
	ret.w = 1.0;
	return (ret);
}

void			enemy_boss_spawn(t_engine *engine)
{
	int				i;
	t_mesh			*target;
	t_mesh			mesh;
	static int		j = 0;

	i = -1;
	while (++i < engine->physic_engine->mesh_list->size)
	{
		target = t_mesh_list_get(engine->physic_engine->mesh_list, i);
		if (ft_strcmp(target->name, "Enemy_boss") == 0)
		{
			if (j == 0)
				j = engine->tick;
			if (engine->tick - j == 3)
			{
				mesh = create_cube(spawn_mine(target->pos),
						new_vec4(0.3, 0.5, 0.3), NULL, 0.0);
				t_mesh_set_color(&mesh, new_color(0.0, 0.0, 0.0, 1.0));
				t_mesh_set_name(&mesh, "Enemy_mine");
				mesh.hp = 10;
				t_engine_add_mesh(engine, mesh);
				j = engine->tick;
			}
		}
	}
}
