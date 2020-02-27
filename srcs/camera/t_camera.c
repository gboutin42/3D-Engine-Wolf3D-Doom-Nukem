/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_camera.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:18:59 by spuisais          #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		new_camera2(t_camera *result)
{
	result->model = new_matrix();
	t_camera_look_at(result);
	result->view = t_camera_compute_view(result);
	result->projection = compute_projection_matrix(result);
	result->sun_direction = normalize_t_vec4(new_vec4(0.2, -1, -0.4));
	result->triangle_color_list = new_triangle_list();
	result->color_list = new_color_list();
	result->triangle_texture_list = new_triangle_list();
	result->uv_list = new_uv_list();
	result->darkness_list = new_color_list();
	result->draw_weapon = 1;
}

t_camera	new_camera(t_window *window, t_vec4 p_pos, float p_fov,
															t_vec2 p_dist)
{
	t_camera	result;

	result.view_port = initialize_t_view_port(window,
				create_vec2_int(0, 0), create_vec2_int(window->size_x,
				window->size_y));
	result.body = NULL;
	result.pos = p_pos;
	result.fov = p_fov;
	result.near = p_dist.x;
	result.far = p_dist.y;
	result.dist_max = 0.0f;
	result.yaw = 0.0f;
	result.pitch = 0.0f;
	result.speed = 0.1f;
	result.running = 1.8f;
	result.slowing = 1.0f;
	result.crouch = 0;
	result.f_press = 0;
	result.r_press = 0;
	new_camera2(&result);
	return (result);
}

t_camera	*initialize_t_camera(t_window *window, t_vec4 p_pos,
												float p_fov, t_vec2 p_dist)
{
	t_camera	*result;

	if (!(result = (t_camera *)ft_memalloc(sizeof(t_camera))))
		error_exit(-31, "Can't ft_memalloc a t_camera");
	*result = new_camera(window, p_pos, p_fov, p_dist);
	return (result);
}

void		jet_pack(t_camera *cam, t_player *player, t_engine *engine)
{
	static int	in_air = 0;

	if (cam->body->force.y != 0.0 && player->fuel > 0)
		in_air = 1;
	if (cam->body->force.y > 0.02)
	{
		if (!Mix_Playing(3) && player->fuel > 0)
			Mix_PlayChannel(3, engine->sound_engine->sounds[3], 0);
		if (player->fuel == 0 && in_air == 1)
		{
			Mix_HaltChannel(3);
			Mix_PlayChannel(3, engine->sound_engine->sounds[4], 0);
		}
	}
	if (cam->body->force.y == 0.0 && in_air == 1)
	{
		in_air = 0;
		Mix_PlayChannel(4, engine->sound_engine->sounds[6], 0);
	}
}

void		handle_camera_mouvement_by_key(t_camera *cam, t_keyboard *keyboard,
															t_engine *engine)
{
	t_vec4		tmp;
	t_vec4		save;
	float		y;
	float		z;

	z = 0.0;
	if (engine->user_engine->player->hitbox.kinetic == 0.0f && (z = 0.1))
		cam->body->force = new_vec4(0.0, 0.0, 0.0);
	jet_pack(cam, engine->user_engine->player, engine);
	jump(keyboard, engine->user_engine->player, cam, engine);
	y = cam->body->force.y;
	if (get_key_state(keyboard, keyboard->key[SDL_SCANCODE_LSHIFT]) == 1
													&& cam->body->force.y == 0)
		tmp = new_vec4(cam->speed * cam->running, z, cam->speed * cam->running);
	else
		tmp = new_vec4(cam->speed, z, cam->speed);
	save = forward_backward(keyboard, cam, tmp, new_vec4(0, 0, 0));
	save = left_right(keyboard, cam, tmp, save);
	if (y != 0.0f)
		cam->body->force = new_vec4(save.x, y, save.z);
	else
		cam->body->force = save;
	move_camera(cam, engine, control_up_down(keyboard, cam, engine));
	cam->body->force = mult_2_vec4(cam->body->force, new_vec4(0.0, 1.0, 0.0));
}
