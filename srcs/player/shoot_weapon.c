/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot_weapon.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:48:54 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:48:55 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	animate_weapon(t_camera *cam, t_texture **texture_weapons,
															t_weapon *weapon)
{
	t_view_port_clear_buffers(cam->view_port);
	draw_rectangle_texture_cpu(cam->view_port,
			new_rectangle(create_vec2(-0.65, -0.1), create_vec2(1.3, -0.9)),
	texture_weapons[weapon->index + 6]);
}

void	shoot_weapon2(t_engine *engine, t_weapon *weapon, t_mesh *target,
						float dist)
{
	target = cast_ray(engine, t_camera_list_get(
	engine->visual_engine->camera_list, 0)->pos, t_camera_list_get(
	engine->visual_engine->camera_list, 0)->forward, "Player");
	if (target != NULL && target->hp > 0)
	{
		if (ft_strcmp(weapon->name, "shotgun") == 0)
			dist = calc_dist_vec4(
				engine->user_engine->player->hitbox.pos, target->pos);
		if (weapon->dmg - dist * 4 >= 0)
			target->hp -= weapon->dmg - dist * 4;
		if (target->hp <= 0)
		{
			if (ft_strcmp(target->name, "wall_script") == 0)
			{
				Mix_PlayChannel(-1, engine->sound_engine->sounds[14], 0);
				activate_gravity(&engine->user_engine->player->hitbox, 0.0f);
				weapon->index = 5;
				change_weapon(engine->user_engine->keyboard,
					engine->user_engine->player);
				engine->display_skybox = 1;
			}
			destroy_mesh(target);
		}
	}
	Mix_PlayChannel(-1, engine->sound_engine->sounds[weapon->index + 7], 0);
}

void	shoot_pistol(t_engine *engine, t_weapon *weapon,
									t_texture **texture_weapons, t_camera *cam)
{
	static int	tick = 1;
	t_mesh		*target;

	target = NULL;
	if (t_mouse_state(engine->user_engine->mouse) == 1 && tick
													% weapon->tick_shoot == 0)
	{
		if (weapon->ammo > 0)
		{
			animate_weapon(cam, texture_weapons, weapon);
			shoot_weapon2(engine, weapon, target, 0.0);
			weapon->ammo--;
		}
		tick = 1;
	}
	else if (tick > 20)
		tick = 1;
	else
		tick++;
}

void	shoot_weapon(t_engine *engine, t_camera *cam,
													t_texture **texture_weapons)
{
	t_mesh		*target;
	t_weapon	*weapon;
	float		dist;

	dist = 0.0;
	target = NULL;
	weapon = engine->user_engine->player->current_weapon;
	if (ft_strcmp(weapon->name, "bb") == 0)
		return ;
	if (ft_strcmp(weapon->name, "pistol") == 0)
		shoot_pistol(engine, weapon, texture_weapons, cam);
	else if (t_mouse_state(engine->user_engine->mouse) == 1 && engine->tick
		% weapon->tick_shoot == 0)
	{
		if (weapon->ammo > 0)
		{
			animate_weapon(cam, texture_weapons, weapon);
			shoot_weapon2(engine, weapon, target, dist);
			if (ft_strcmp(weapon->name, "ar") == 0)
				weapon->ammo -= 2;
			weapon->ammo--;
		}
		engine->user_engine->player->shoot_time = engine->tick;
	}
}
