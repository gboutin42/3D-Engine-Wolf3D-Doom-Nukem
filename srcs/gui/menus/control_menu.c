/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_menu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:48:47 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		set_controls(t_camera *main_camera, t_gui *gui,
											t_user_engine *user_engine, int key)
{
	int	scan_code;

	draw_rectangle_texture_cpu(main_camera->view_port,
		new_rectangle(create_vec2(-1, 1), create_vec2(2, -2)), gui->menu[11]);
	scan_code = user_engine->event.key.keysym.scancode;
	if (scan_code >= 4 && scan_code <= 231)
	{
		if (get_key_state(user_engine->keyboard, scan_code) == 1)
		{
			user_engine->keyboard->key[key] = scan_code;
			reset_key_state(user_engine->keyboard, scan_code);
			gui->key_press = 0;
		}
	}
}

void		control_right_part(t_vec2_int pos, t_gui *gui)
{
	if (pos.y > 28 && pos.y < 32)
	{
		gui->key_change = SDL_SCANCODE_LCTRL;
		gui->key_press = 2;
	}
	else if (pos.y > 39 && pos.y < 44)
	{
		gui->key_change = SDL_SCANCODE_SPACE;
		gui->key_press = 2;
	}
	else if (pos.y > 51 && pos.y < 57)
	{
		gui->key_change = SDL_SCANCODE_LSHIFT;
		gui->key_press = 2;
	}
	else if (pos.y > 64 && pos.y < 69)
	{
		gui->key_change = SDL_SCANCODE_F;
		gui->key_press = 2;
	}
}

void		control_left_part(t_vec2_int pos, t_gui *gui)
{
	if (pos.y > 28 && pos.y < 32)
	{
		gui->key_change = SDL_SCANCODE_W;
		gui->key_press = 2;
	}
	else if (pos.y > 39 && pos.y < 44)
	{
		gui->key_change = SDL_SCANCODE_S;
		gui->key_press = 2;
	}
	else if (pos.y > 51 && pos.y < 57)
	{
		gui->key_change = SDL_SCANCODE_A;
		gui->key_press = 2;
	}
	else if (pos.y > 64 && pos.y < 69)
	{
		gui->key_change = SDL_SCANCODE_D;
		gui->key_press = 2;
	}
}

void		controls_menu(t_camera *main_camera, t_gui *gui, t_engine *engine)
{
	t_mouse		*mou;
	t_vec2_int	pos;

	mou = engine->user_engine->mouse;
	get_t_mouse_info(mou);
	pos = create_vec2_int(mou->pos.x * 100 / WIN_X, mou->pos.y * 100 / WIN_Y);
	if (gui->key_press != 2)
	{
		if (t_mouse_state(mou) == 2)
		{
			Mix_PlayChannel(-1, engine->sound_engine->sounds[0], 0);
			if (pos.x > 23 && pos.x < 44)
				control_left_part(pos, gui);
			if (pos.x > 64 && pos.x < 76)
				control_right_part(pos, gui);
			if (pos.x > 43 && pos.x < 56)
				if (pos.y > 82 && pos.y < 86)
					engine->menu_nbr = 1;
		}
	}
	else if (gui->key_press == 2)
		set_controls(main_camera, gui, engine->user_engine, gui->key_change);
}
