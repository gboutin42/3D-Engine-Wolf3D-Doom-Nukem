/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_mesh_editor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:47:26 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:47:27 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		rotate_mesh(t_engine *engine)
{
	t_mesh		*target;

	if (get_key_state(engine->user_engine->keyboard,
	engine->user_engine->keyboard->key[SDL_SCANCODE_PERIOD]) == 1)
	{
		target = cast_ray(engine,
		t_camera_list_get(engine->visual_engine->camera_list, 0)->pos,
		t_camera_list_get(engine->visual_engine->camera_list, 0)->forward,
																"Player");
		if (target != NULL)
			t_mesh_rotate(target, new_vec4(0.0, 10.0, 0.0));
	}
	else if (get_key_state(engine->user_engine->keyboard,
			engine->user_engine->keyboard->key[SDL_SCANCODE_COMMA]) == 1)
	{
		target = cast_ray(engine,
		t_camera_list_get(engine->visual_engine->camera_list, 0)->pos,
		t_camera_list_get(engine->visual_engine->camera_list, 0)->forward,
																"Player");
		if (target != NULL)
			t_mesh_rotate(target, new_vec4(0.0, -10.0, 0.0));
	}
}

void		left_move(t_engine *engine)
{
	t_mesh		*target;
	static int	press = 0;

	if (get_key_state(engine->user_engine->keyboard,
	engine->user_engine->keyboard->key[SDL_SCANCODE_LEFT]) == 1
												&& press == 0)
	{
		target = cast_ray(engine,
		t_camera_list_get(engine->visual_engine->camera_list, 0)->pos,
		t_camera_list_get(engine->visual_engine->camera_list, 0)->forward,
																"Player");
		if (target != NULL)
		{
			press = 1;
			t_mesh_move(target, new_vec4(0.0, 0.0, 0.1));
		}
	}
	else if (get_key_state(engine->user_engine->keyboard,
	engine->user_engine->keyboard->key[SDL_SCANCODE_LEFT]) == 0)
		press = 0;
}

void		right_move(t_engine *engine)
{
	t_mesh		*target;
	static int	press = 0;

	if (get_key_state(engine->user_engine->keyboard,
	engine->user_engine->keyboard->key[SDL_SCANCODE_RIGHT]) == 1
												&& press == 0)
	{
		target = cast_ray(engine,
		t_camera_list_get(engine->visual_engine->camera_list, 0)->pos,
		t_camera_list_get(engine->visual_engine->camera_list, 0)->forward,
																"Player");
		if (target != NULL)
		{
			press = 1;
			t_mesh_move(target, new_vec4(0.0, 0.0, -0.1));
		}
	}
	else if (get_key_state(engine->user_engine->keyboard,
	engine->user_engine->keyboard->key[SDL_SCANCODE_RIGHT]) == 0)
		press = 0;
}

void		up_move(t_engine *engine)
{
	t_mesh		*target;
	static int	press = 0;

	if (get_key_state(engine->user_engine->keyboard,
	engine->user_engine->keyboard->key[SDL_SCANCODE_UP]) == 1 && press == 0)
	{
		target = cast_ray(engine,
		t_camera_list_get(engine->visual_engine->camera_list, 0)->pos,
		t_camera_list_get(engine->visual_engine->camera_list, 0)->forward,
																"Player");
		if (target != NULL)
		{
			press = 1;
			t_mesh_move(target, new_vec4(0.1, 0.0, 0.0));
		}
	}
	else if (get_key_state(engine->user_engine->keyboard,
		engine->user_engine->keyboard->key[SDL_SCANCODE_UP]) == 0)
		press = 0;
}

void		down_move(t_engine *engine)
{
	t_mesh		*target;
	static int	press = 0;

	if (get_key_state(engine->user_engine->keyboard,
	engine->user_engine->keyboard->key[SDL_SCANCODE_DOWN]) == 1
												&& press == 0)
	{
		target = cast_ray(engine,
		t_camera_list_get(engine->visual_engine->camera_list, 0)->pos,
		t_camera_list_get(engine->visual_engine->camera_list, 0)->forward,
																"Player");
		if (target != NULL)
		{
			press = 1;
			t_mesh_move(target, new_vec4(-0.1, 0.0, 0.0));
		}
	}
	else if (get_key_state(engine->user_engine->keyboard,
	engine->user_engine->keyboard->key[SDL_SCANCODE_DOWN]) == 0)
		press = 0;
}
