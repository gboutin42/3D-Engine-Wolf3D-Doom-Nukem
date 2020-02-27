/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_editor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:47:19 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:47:21 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		player_editing(t_engine *engine)
{
	static int	b_press = 0;
	static int	print = 0;

	if (print == 1 && engine->playing == 4)
		print = 0;
	if (get_key_state(engine->user_engine->keyboard,
		engine->user_engine->keyboard->key[SDL_SCANCODE_B]) == 1
		&& b_press == 0)
	{
		print = 1;
		b_press = 1;
	}
	else if (get_key_state(engine->user_engine->keyboard,
		engine->user_engine->keyboard->key[SDL_SCANCODE_B]) == 0)
		b_press = 0;
	if (print == 1)
	{
		engine->menu_nbr = 14;
		engine->playing = 5;
	}
}

void		delete_mesh(t_engine *engine)
{
	t_mesh		*target;
	static int	click = 0;

	if (get_mouse_state(engine->user_engine->mouse, MOUSE_RIGHT) == 1
																&& click == 0)
	{
		target = cast_ray(engine,
			t_camera_list_get(engine->visual_engine->camera_list, 0)->pos,
			t_camera_list_get(engine->visual_engine->camera_list, 0)->forward,
																	"Player");
		if (target != NULL && ft_strcmp(target->name, "Player") != 0)
		{
			t_mesh_set_visibility(target, BOOL_FALSE);
			target->no_hitbox = 1;
		}
		click = 1;
	}
	else if (get_mouse_state(engine->user_engine->mouse, MOUSE_RIGHT) == 0
																&& click == 1)
		click = 0;
}

void		activate_hitbox(t_engine *engine)
{
	t_mesh		*target;
	static int	press = 0;

	if (get_key_state(engine->user_engine->keyboard,
		engine->user_engine->keyboard->key[SDL_SCANCODE_L]) == 1 && press == 0)
	{
		target = cast_ray(engine,
			t_camera_list_get(engine->visual_engine->camera_list, 0)->pos,
			t_camera_list_get(engine->visual_engine->camera_list, 0)->forward,
																	"Player");
		if (target != NULL && ft_strcmp(target->name, "Player") != 0)
		{
			if (target->no_hitbox == 0)
				target->no_hitbox = 1;
			else
				target->no_hitbox = 0;
			press = 1;
		}
	}
	else if (get_key_state(engine->user_engine->keyboard,
				engine->user_engine->keyboard->key[SDL_SCANCODE_L]) == 0)
		press = 0;
}

void		activate_visibility(t_engine *engine)
{
	t_mesh		*target;
	static int	press = 0;

	if (get_key_state(engine->user_engine->keyboard,
		engine->user_engine->keyboard->key[SDL_SCANCODE_I]) == 1 && press == 0)
	{
		target = cast_ray(engine,
			t_camera_list_get(engine->visual_engine->camera_list, 0)->pos,
			t_camera_list_get(engine->visual_engine->camera_list, 0)->forward,
																	"Player");
		if (target != NULL && ft_strcmp(target->name, "Player") != 0)
		{
			if (target->is_visible == 0)
				target->is_visible = 1;
			else
				target->is_visible = 0;
			press = 1;
		}
	}
	else if (get_key_state(engine->user_engine->keyboard,
		engine->user_engine->keyboard->key[SDL_SCANCODE_I]) == 0)
		press = 0;
}

void		map_editor(t_camera *cam, t_gui *gui, t_engine *engine,
													t_mesh_editing mesh_editing)
{
	static t_color	*color = NULL;

	if (color == NULL)
		color = initialize_t_color(0.3, 0.3, 1.0, 1.0);
	t_view_port_clear_buffers(cam->view_port);
	draw_hud_rect(cam->view_port, new_rectangle(create_vec2(0.0, 0.0),
											create_vec2(0.005, 0.01)), color);
	print_info_editing(cam, engine->user_engine->keyboard, gui);
	print_info_texture(cam, gui, mesh_editing);
	player_editing(engine);
	place_mesh(engine, mesh_editing);
	delete_mesh(engine);
	activate_hitbox(engine);
	activate_visibility(engine);
	rotate_mesh(engine);
	left_move(engine);
	right_move(engine);
	up_move(engine);
	down_move(engine);
	equals_move(engine);
	minus_move(engine);
}
