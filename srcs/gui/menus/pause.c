/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pause.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:46:29 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:46:30 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	close_map(t_engine *engine)
{
	free_t_physic_engine(&engine->physic_engine);
	free_t_visual_engine(&engine->visual_engine);
	ft_memdel((void**)&engine->user_engine->player);
	engine->physic_engine = initialize_t_physic_engine();
	engine->visual_engine = initialize_t_visual_engine(engine->win);
	create_minimap(engine);
	engine->playing = 1;
	engine->menu_nbr = 0;
}

void	pause_menu(t_engine *engine)
{
	t_mouse		*mou;
	t_vec2_int	pos;

	mou = engine->user_engine->mouse;
	get_t_mouse_info(mou);
	pos = create_vec2_int(mou->pos.x * 100 / WIN_X, mou->pos.y * 100 / WIN_Y);
	if (pos.x > 39 && pos.x < 61)
	{
		if (t_mouse_state(mou) == 2)
		{
			if (pos.y > 26 && pos.y < 32)
				engine->playing = 2;
			else if (pos.y > 36 && pos.y < 41)
				engine->menu_nbr = 5;
			else if (pos.y > 45 && pos.y < 50)
				engine->menu_nbr = 16;
			else if (pos.y > 64 && pos.y < 70)
				engine->playing = 0;
			Mix_PlayChannel(-1, engine->sound_engine->sounds[0], 0);
		}
	}
	else
		engine->user_engine->mouse->clicked_left = BOOL_FALSE;
}

void	mute_unmute(void)
{
	if (Mix_VolumeMusic(-1) == 128 || Mix_Volume(-1, -1) == 128)
	{
		Mix_VolumeMusic(0);
		Mix_Volume(-1, 0);
	}
	else if (Mix_VolumeMusic(-1) == 0 || Mix_Volume(-1, -1) == 0)
	{
		Mix_VolumeMusic(MIX_MAX_VOLUME);
		Mix_Volume(-1, MIX_MAX_VOLUME);
	}
}

void	sens_pause(t_mouse *mouse, t_vec2_int pos)
{
	if (pos.y > 42 && pos.y < 46)
	{
		if (mouse->sens == 5)
			mouse->sens = mouse->sens - 2;
		else if (mouse->sens > 5)
			mouse->sens = mouse->sens - 5;
	}
	if (pos.y > 55 && pos.y < 60)
	{
		if (mouse->sens == 3)
			mouse->sens = mouse->sens + 2;
		else if (mouse->sens < 20)
			mouse->sens = mouse->sens + 5;
	}
}

void	settings_pause_menu(t_engine *engine)
{
	t_mouse		*mou;
	t_vec2_int	pos;

	mou = engine->user_engine->mouse;
	get_t_mouse_info(mou);
	pos = create_vec2_int(mou->pos.x * 100 / WIN_X, mou->pos.y * 100 / WIN_Y);
	if (pos.x > 34 && pos.x < 64)
	{
		if (t_mouse_state(mou) == 2)
		{
			if (pos.y > 26 && pos.y < 32)
				mute_unmute();
			if (pos.y > 69 && pos.y < 75)
				engine->menu_nbr = 4;
			sens_pause(engine->user_engine->mouse, pos);
			Mix_PlayChannel(-1, engine->sound_engine->sounds[0], 0);
		}
	}
}
