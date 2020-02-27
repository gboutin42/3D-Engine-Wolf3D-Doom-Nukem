/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_menu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:45:37 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	settings_sounds(t_vec2_int pos)
{
	if (pos.y > 23 && pos.y < 26)
	{
		if (Mix_VolumeMusic(-1) == 0)
			Mix_VolumeMusic(MIX_MAX_VOLUME);
		else if (Mix_VolumeMusic(-1) == 128)
			Mix_VolumeMusic(0);
		if (Mix_Volume(-1, -1) == 0)
			Mix_Volume(-1, MIX_MAX_VOLUME);
		else if (Mix_Volume(-1, -1) == 128)
			Mix_Volume(-1, 0);
	}
	if (pos.y > 27 && pos.y < 30)
	{
		if (Mix_VolumeMusic(-1) == 0)
			Mix_VolumeMusic(MIX_MAX_VOLUME);
		else if (Mix_VolumeMusic(-1) == 128)
			Mix_VolumeMusic(0);
	}
	if (pos.y > 32 && pos.y < 35)
	{
		if (Mix_Volume(-1, -1) == 0)
			Mix_Volume(-1, MIX_MAX_VOLUME);
		else if (Mix_Volume(-1, -1) == 128)
			Mix_Volume(-1, 0);
	}
}

void	settings_sens(t_vec2_int pos, t_engine *engine)
{
	if (pos.y >= 66 && pos.y <= 69)
	{
		if (pos.x >= 16 && pos.x <= 18)
			engine->user_engine->mouse->sens = 20;
		else if (pos.x >= 19 && pos.x <= 21)
			engine->user_engine->mouse->sens = 15;
		else if (pos.x >= 23 && pos.x <= 25)
			engine->user_engine->mouse->sens = 10;
		else if (pos.x >= 27 && pos.x <= 29)
			engine->user_engine->mouse->sens = 5;
		else if (pos.x >= 30 && pos.x <= 32)
			engine->user_engine->mouse->sens = 3;
	}
}

void	settings_difficulty(t_vec2_int pos, t_camera *main_camera,
												t_gui *gui, t_engine *engine)
{
	if (pos.y > 44 && pos.y < 47)
	{
		draw_rectangle_texture_cpu(main_camera->view_port,
				new_rectangle(create_vec2(0.7, 0.4),
				create_vec2(-0.6, -0.94)), gui->menu[8]);
		gui->idx = 8;
		engine->difficulty = 0.5;
	}
	if (pos.y > 48 && pos.y < 52)
	{
		draw_rectangle_texture_cpu(main_camera->view_port,
				new_rectangle(create_vec2(0.7, 0.4),
				create_vec2(-0.6, -0.94)), gui->menu[9]);
		gui->idx = 9;
		engine->difficulty = 1.0;
	}
	if (pos.y > 53 && pos.y < 56)
	{
		draw_rectangle_texture_cpu(main_camera->view_port,
				new_rectangle(create_vec2(0.7, 0.4),
				create_vec2(-0.6, -0.94)), gui->menu[10]);
		gui->idx = 10;
		engine->difficulty = 1.5;
	}
}

void	settings_menu_next(t_camera *main_camera, t_gui *gui,
											t_vec2_int pos, t_engine *engine)
{
	settings_sounds(pos);
	settings_sens(pos, engine);
	settings_difficulty(pos, main_camera, gui, engine);
	if (pos.y > 72 && pos.y < 76)
		engine->menu_nbr = 2;
}

void	settings_menu(t_camera *main_camera, t_gui *gui, t_engine *engine)
{
	t_mouse		*mou;
	t_vec2_int	pos;

	mou = engine->user_engine->mouse;
	get_t_mouse_info(mou);
	pos = create_vec2_int(mou->pos.x * 100 / WIN_X, mou->pos.y * 100 / WIN_Y);
	t_view_port_clear_buffers(main_camera->view_port);
	draw_rectangle_texture_cpu(main_camera->view_port,
			new_rectangle(create_vec2(0.7, 0.4), create_vec2(-0.6, -0.94)),
														gui->menu[gui->idx]);
	if (t_mouse_state(mou) == 2)
	{
		if (pos.x > 16 && pos.x < 32)
			settings_menu_next(main_camera, gui, pos, engine);
		else if (pos.x > 43 && pos.x < 56)
			engine->menu_nbr = 0;
		Mix_PlayChannel(-1, engine->sound_engine->sounds[0], 0);
	}
}
