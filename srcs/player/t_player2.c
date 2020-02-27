/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_player2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:49:07 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:49:08 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	change_weapon(t_keyboard *p_keyboard, t_player *player)
{
	static int index = 0;

	if (ft_strcmp(player->current_weapon->name, "bb") == 0)
		index = 5;
	else if (get_key_state(p_keyboard, p_keyboard->key[SDL_SCANCODE_1]) == 1)
		index = 0;
	else if (get_key_state(p_keyboard, p_keyboard->key[SDL_SCANCODE_2]) == 1
										&& player->weapons[1].total_ammo >= 0)
		index = 1;
	else if (get_key_state(p_keyboard, p_keyboard->key[SDL_SCANCODE_3]) == 1
										&& player->weapons[2].total_ammo >= 0)
		index = 2;
	else if (get_key_state(p_keyboard, p_keyboard->key[SDL_SCANCODE_4]) == 1
										&& player->weapons[3].total_ammo >= 0)
		index = 3;
	else if (get_key_state(p_keyboard, p_keyboard->key[SDL_SCANCODE_5]) == 1
										&& player->weapons[4].total_ammo >= 0)
		index = 4;
	player->current_weapon = &player->weapons[index];
}

void	drawing_front_reload(t_camera *cam)
{
	static t_texture	*icon = NULL;

	if (icon == NULL)
		icon = png_load("ressources/assets/imgs/reload_icon.png");
	t_view_port_clear_buffers(cam->view_port);
	draw_rectangle_texture_cpu(cam->view_port, new_rectangle(
					create_vec2(0.1, 0.1), create_vec2(-0.2, -0.2)),
					icon);
}

void	reload_weapon(t_camera *camera, t_player *player, int tick,
						t_engine *engine)
{
	int			to_fill;
	t_weapon	*weapon;

	weapon = engine->user_engine->player->current_weapon;
	if (weapon->index == 5)
		return ;
	to_fill = weapon->mag_size - weapon->ammo;
	if (!Mix_Playing(5) && tick - player->reload_time == 0)
		Mix_PlayChannel(5, engine->sound_engine->sounds[weapon->index + 18], 0);
	if (tick - player->reload_time < weapon->tick_reload)
		drawing_front_reload(camera);
	if (tick - player->reload_time == weapon->tick_reload)
	{
		while (to_fill > 0 && weapon->ammo < weapon->mag_size
			&& weapon->total_ammo > 0)
		{
			weapon->ammo++;
			weapon->total_ammo--;
			if (ft_strcmp(weapon->name, "pistol") == 0
				&& weapon->ammo == weapon->mag_size)
				weapon->total_ammo = 15;
		}
		camera->r_press = 0;
	}
}
