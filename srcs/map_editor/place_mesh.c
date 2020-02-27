/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_mesh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:47:39 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/25 11:55:36 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		check_mesh_player(t_engine *engine, t_mesh mesh)
{
	int			i;
	t_mesh		*target;

	i = 0;
	while (i < engine->physic_engine->mesh_list->size)
	{
		target = t_mesh_list_get(engine->physic_engine->mesh_list, i);
		if (ft_strcmp(target->name, "Player") == 0)
		{
			target->is_visible = 0;
			target->no_hitbox = 1;
			t_mesh_set_name(target, "mesh");
		}
		i++;
	}
	engine->user_engine->player->hitbox = mesh;
}

void		place_mesh_bis(t_engine *engine, t_mesh_editing edit, t_mesh *mesh)
{
	t_mesh_set_color(mesh, new_color(1.0, 1.0, 1.0, 1.0));
	t_mesh_set_name(mesh, edit.mesh.name);
	mesh->hp = edit.mesh.hp;
	t_mesh_rotate(mesh, edit.mesh.rotation);
	cast_mesh(engine, mesh);
	mesh->pos.x = round_float(mesh->pos.x, 2);
	mesh->pos.y = round_float(mesh->pos.y, 2);
	mesh->pos.z = round_float(mesh->pos.z, 2);
	if (ft_strcmp(mesh->name, "Player") == 0)
		check_mesh_player(engine, *mesh);
}

void		set_collectible(t_mesh *mesh, t_mesh_editing edit)
{
	char		*str;
	static int	i = 1;

	mesh->collectible = edit.mesh.collectible;
	if (mesh->collectible == 1 && ft_strcmp(mesh->name, "Card_red") != 0
								&& ft_strcmp(mesh->name, "Card_blue") != 0
								&& ft_strcmp(mesh->name, "Card_green") != 0)
	{
		str = ft_itoa(i);
		mesh->name = ft_strjoinf(mesh->name, str, 3);
		i++;
	}
}

void		place_mesh(t_engine *engine, t_mesh_editing edit)
{
	t_mesh		mesh;

	if (t_mouse_state(engine->user_engine->mouse) == 2
							&& engine->physic_engine->mesh_list->size < 249)
	{
		if (edit.mesh.primitive == 1 || edit.mesh.primitive == -1)
		{
			if (edit.mesh.primitive == -1)
			{
				mesh = create_cube(edit.mesh.pos,
					edit.mesh.size, NULL, edit.mesh.kinetic);
				mesh.primitive = -1;
			}
			else
				mesh = create_cube(edit.mesh.pos,
					edit.mesh.size, edit.path, edit.mesh.kinetic);
		}
		else if (edit.mesh.primitive == 0)
			mesh = create_plane(edit.mesh.pos,
				edit.mesh.size, edit.path, edit.mesh.kinetic);
		place_mesh_bis(engine, edit, &mesh);
		set_collectible(&mesh, edit);
		t_engine_add_mesh(engine, mesh);
	}
}
