/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:46:41 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:46:42 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		save_pause_ter(t_engine *engine, t_vec2_int pos)
{
	if (pos.y > 57 && pos.y < 65)
	{
		save_map(engine, 4);
		if (engine->playing == 5)
			engine->playing = 4;
		if (engine->playing == 3)
			engine->menu_nbr = 4;
	}
	if (pos.y > 72 && pos.y < 80)
	{
		save_map(engine, 5);
		if (engine->playing == 5)
			engine->playing = 4;
		if (engine->playing == 3)
			engine->menu_nbr = 4;
	}
	if (pos.y > 91 && pos.y < 98)
	{
		if (engine->playing == 5)
			engine->menu_nbr = 14;
		if (engine->playing == 3)
			engine->menu_nbr = 4;
	}
}

void		save_pause_bis(t_engine *engine, t_vec2_int pos)
{
	if (pos.y > 10 && pos.y < 18)
	{
		save_map(engine, 1);
		if (engine->playing == 5)
			engine->playing = 4;
		if (engine->playing == 3)
			engine->menu_nbr = 4;
	}
	if (pos.y > 26 && pos.y < 34)
	{
		save_map(engine, 2);
		if (engine->playing == 5)
			engine->playing = 4;
		if (engine->playing == 3)
			engine->menu_nbr = 4;
	}
	if (pos.y > 41 && pos.y < 49)
	{
		save_map(engine, 3);
		if (engine->playing == 5)
			engine->playing = 4;
		if (engine->playing == 3)
			engine->menu_nbr = 4;
	}
}

void		save_pause(t_engine *engine)
{
	t_mouse		*mou;
	t_vec2_int	pos;

	mou = engine->user_engine->mouse;
	get_t_mouse_info(mou);
	pos = create_vec2_int(mou->pos.x * 100 / WIN_X, mou->pos.y * 100 / WIN_Y);
	if (pos.x > 40 && pos.x < 61)
	{
		if (t_mouse_state(mou) == 2)
		{
			save_pause_bis(engine, pos);
			save_pause_ter(engine, pos);
			Mix_PlayChannel(-1, engine->sound_engine->sounds[0], 0);
		}
	}
}
