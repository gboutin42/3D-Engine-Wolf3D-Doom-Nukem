/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_weapon_editing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:07:01 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		set_ar_editing(t_vec2_int pos, t_player *player)
{
	if (pos.y > 11 && pos.y < 15)
	{
		if (pos.x > 44 && pos.x < 48)
			player->weapons[1].total_ammo = 0;
		if (pos.x > 50 && pos.x < 55)
			player->weapons[1].total_ammo = -1;
	}
	if (pos.y > 18 && pos.y < 22)
	{
		player->weapons[1].ammo = 30;
		if (pos.x >= 52 && pos.x <= 54)
			player->weapons[1].ammo = 0;
		if ((pos.x >= 55 && pos.x <= 57) || (pos.x >= 52 && pos.x <= 54))
			player->weapons[1].total_ammo = 0;
		if (pos.x >= 58 && pos.x <= 60)
			player->weapons[1].total_ammo = 30;
		if (pos.x >= 61 && pos.x <= 63)
			player->weapons[1].total_ammo = 60;
		if (pos.x >= 64 && pos.x <= 66)
			player->weapons[1].total_ammo = 90;
		if (pos.x >= 67 && pos.x <= 69)
			player->weapons[1].total_ammo = 120;
	}
}

void		set_rifle_editing(t_vec2_int pos, t_player *player)
{
	if (pos.y > 53 && pos.y < 57)
	{
		if (pos.x > 44 && pos.x < 48)
			player->weapons[2].total_ammo = 0;
		if (pos.x > 50 && pos.x < 55)
			player->weapons[2].total_ammo = -1;
	}
	if (pos.y > 60 && pos.y < 64)
	{
		player->weapons[2].ammo = 10;
		if (pos.x >= 52 && pos.x <= 54)
			player->weapons[2].ammo = 0;
		if ((pos.x >= 55 && pos.x <= 57) || (pos.x >= 52 && pos.x <= 54))
			player->weapons[2].total_ammo = 0;
		if (pos.x >= 58 && pos.x <= 60)
			player->weapons[2].total_ammo = 10;
		if (pos.x >= 61 && pos.x <= 63)
			player->weapons[2].total_ammo = 20;
		if (pos.x >= 64 && pos.x <= 66)
			player->weapons[2].total_ammo = 30;
		if (pos.x >= 67 && pos.x <= 69)
			player->weapons[2].total_ammo = 40;
	}
}

void		set_shotgun_editing(t_vec2_int pos, t_player *player)
{
	if (pos.y > 32 && pos.y < 36)
	{
		if (pos.x > 44 && pos.x < 48)
			player->weapons[3].total_ammo = 0;
		if (pos.x > 50 && pos.x < 55)
			player->weapons[3].total_ammo = -1;
	}
	if (pos.y > 39 && pos.y < 43)
	{
		player->weapons[3].ammo = 8;
		if (pos.x >= 52 && pos.x <= 54)
			player->weapons[3].ammo = 0;
		if ((pos.x >= 55 && pos.x <= 57) || (pos.x >= 52 && pos.x <= 54))
			player->weapons[3].total_ammo = 0;
		if (pos.x >= 58 && pos.x <= 60)
			player->weapons[3].total_ammo = 8;
		if (pos.x >= 61 && pos.x <= 63)
			player->weapons[3].total_ammo = 16;
		if (pos.x >= 64 && pos.x <= 66)
			player->weapons[3].total_ammo = 24;
		if (pos.x >= 67 && pos.x <= 69)
			player->weapons[3].total_ammo = 32;
	}
}

void		set_rpg_editing(t_vec2_int pos, t_player *player)
{
	if (pos.y > 74 && pos.y < 78)
	{
		if (pos.x > 44 && pos.x < 48)
			player->weapons[4].total_ammo = 0;
		if (pos.x > 50 && pos.x < 55)
			player->weapons[4].total_ammo = -1;
	}
	if (pos.y > 81 && pos.y < 85)
	{
		player->weapons[4].ammo = 1;
		if (pos.x >= 52 && pos.x <= 54)
			player->weapons[4].ammo = 0;
		if ((pos.x >= 55 && pos.x <= 57) || (pos.x >= 52 && pos.x <= 54))
			player->weapons[4].total_ammo = 0;
		if (pos.x >= 58 && pos.x <= 60)
			player->weapons[4].total_ammo = 1;
		if (pos.x >= 61 && pos.x <= 63)
			player->weapons[4].total_ammo = 2;
		if (pos.x >= 64 && pos.x <= 66)
			player->weapons[4].total_ammo = 3;
		if (pos.x >= 67 && pos.x <= 69)
			player->weapons[4].total_ammo = 4;
	}
}

void		set_weapon_editing(t_engine *engine)
{
	t_mouse		*mou;
	t_player	*player;
	t_vec2_int	pos;

	mou = engine->user_engine->mouse;
	player = engine->user_engine->player;
	get_t_mouse_info(mou);
	pos = create_vec2_int(mou->pos.x * 100 / WIN_X, mou->pos.y * 100 / WIN_Y);
	if (t_mouse_state(mou) == 2)
	{
		set_ar_editing(pos, player);
		set_shotgun_editing(pos, player);
		set_rifle_editing(pos, player);
		set_rpg_editing(pos, player);
		if (pos.y > 91 && pos.y < 98 && pos.x > 40 && pos.x < 61)
			engine->menu_nbr = 14;
		Mix_PlayChannel(-1, engine->sound_engine->sounds[0], 0);
	}
}
