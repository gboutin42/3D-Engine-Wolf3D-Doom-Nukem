/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physic_engine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:56:08 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int				test_move_axis2(t_mesh *mesh, float *tab, t_vec4 axis,
														t_mesh *target)
{
	float	tmp;

	if (axis.y == 0.0)
	{
		tmp = mesh->force.y;
		mesh->force.y = 0.015;
		axis.y = 1;
		t_mesh_comp_next_vert_world(mesh, axis);
		if (mesh_intersect(mesh, target) == BOOL_TRUE)
		{
			mesh->force.y = tmp;
			tab[0] -= tab[1];
		}
		axis.y = 0.0;
	}
	else
		tab[0] -= tab[1];
	return (20);
}

void			test_move_axis(t_mesh *mesh, float *force, t_vec4 axis,
														t_mesh *target)
{
	float	max;
	int		i;
	float	tab[2];

	tab[1] = *force / 20;
	max = *force;
	*force = 0;
	i = -1;
	while (++i < 20 && mesh_intersect(mesh, target) == BOOL_FALSE)
	{
		*force += tab[1];
		if (i == 20)
			*force = max;
		t_mesh_comp_next_vert_world(mesh, axis);
		if (mesh_intersect(mesh, target) == BOOL_TRUE)
		{
			tab[0] = *force;
			i = test_move_axis2(mesh, tab, axis, target);
			*force = tab[0];
			if (ft_strcmp(target->name, "ladder") == 0 && axis.y == 0.0)
				mesh->force.y = 0.02;
		}
	}
	t_mesh_comp_next_vert_world(mesh, axis);
}

void			can_move3(t_mesh *mesh, t_engine *engine, t_mesh *tar)
{
	if (t_mesh_on_mesh(mesh, tar) == 1 && ft_strcmp(tar->name, "end") == 0)
	{
		engine->playing = 3;
		engine->menu_nbr = 19;
	}
	if (mesh_intersect(mesh, tar) == BOOL_TRUE
		&& (ft_strcmp(tar->name, "stair") == 0))
		mesh->force.y = 0.020;
	else if (tar->collectible == 0)
	{
		test_move_axis(mesh, &(mesh->force.y), new_vec4(0, 1, 0), tar);
		test_move_axis(mesh, &(mesh->force.x), new_vec4(1, 0, 0), tar);
		test_move_axis(mesh, &(mesh->force.z), new_vec4(0, 0, 1), tar);
		if (mesh->force.z != 0.0 && mesh->force.x != 0.0)
		{
			t_mesh_comp_next_vert_world(mesh, new_vec4(1, 1, 1));
			if (mesh_intersect(mesh, tar) == BOOL_TRUE)
			{
				mesh->force.z = 0.0;
				mesh->force.x = 0.0;
			}
			t_mesh_comp_next_vert_world(mesh, new_vec4(1, 1, 1));
		}
	}
}

void			can_move2(t_engine *engine, t_mesh *tar)
{
	int			j;
	t_item_list	*item_list;

	item_list = engine->physic_engine->item_list;
	j = 0;
	while (j < item_list->size)
	{
		if (ft_strcmp(tar->name, t_item_list_get(item_list, j)->name) == 0)
		{
			if (item_list->item[j].pf(engine->user_engine->player) == BOOL_TRUE)
			{
				Mix_PlayChannel(-1, engine->sound_engine->sounds[23], 0);
				t_mesh_set_visibility(tar, BOOL_FALSE);
				tar->no_hitbox = 1;
				break ;
			}
		}
		j++;
	}
}

int				can_move(t_mesh *mesh, t_engine *engine)
{
	t_mesh	*tar;
	int		i;

	i = 0;
	while (i < engine->physic_engine->mesh_list->size)
	{
		tar = t_mesh_list_get(engine->physic_engine->mesh_list, i);
		if (mesh != tar && tar->bubble_radius + mesh->bubble_radius >=
			calc_dist_vec4(mesh->center, tar->center) && tar->no_hitbox == 0)
		{
			if (tar->collectible == 1 && mesh_intersect(mesh, tar) == BOOL_TRUE)
				can_move2(engine, tar);
			if (mesh_intersect(mesh, tar) == BOOL_TRUE
				&& ft_strcmp(tar->name, "Enemy") == '_')
			{
				player_take_dmg(engine, 10);
				if (ft_strcmp(tar->name, "Enemy_mine") == 0)
					destroy_mesh(tar);
			}
			can_move3(mesh, engine, tar);
		}
		i++;
	}
	return (BOOL_TRUE);
}
