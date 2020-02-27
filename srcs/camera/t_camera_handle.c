/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_camera_handle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:18:59 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		jump(t_keyboard *keyboard, t_player *player, t_camera *cam,
															t_engine *engine)
{
	if (get_key_state(keyboard, keyboard->key[SDL_SCANCODE_SPACE]) == 1
														&& player->fuel > 0)
	{
		cam->body->force.y = 0.04;
		player->fuel--;
		if (!Mix_Playing(3))
			Mix_PlayChannel(3, engine->sound_engine->sounds[2], 0);
	}
	else if (get_key_state(keyboard, keyboard->key[SDL_SCANCODE_SPACE]) == 1
													&& cam->body->force.y == 0)
	{
		Mix_PlayChannel(4, engine->sound_engine->sounds[1], 0);
		cam->body->force.y = 0.04;
	}
}

float		control_up_down_next(t_camera *cam, t_mesh_list *meshs)
{
	t_mesh		*tar;
	int			k;
	int			l;
	int			i;

	k = 0;
	l = 0;
	i = -1;
	while (++i < meshs->size)
	{
		tar = t_mesh_list_get(meshs, i);
		if (cam->body != tar && tar->bubble_radius + cam->body->bubble_radius
					>= calc_dist_vec4(cam->body->center, tar->center))
		{
			k++;
			if (cam->body->pos.y > tar->pos.y
					|| tar->pos.y - cam->body->pos.y >= 0.49)
				l++;
		}
	}
	return (k == l ? 0.0 : 0.2);
}

float		control_up_down(t_keyboard *keyboard, t_camera *cam,
													t_engine *engine)
{
	float	j;

	j = 0.0;
	if (get_key_state(keyboard, keyboard->key[SDL_SCANCODE_LCTRL]) == 1)
	{
		j = 0.2;
		if (cam->crouch == 0)
		{
			t_mesh_resize(cam->body, new_vec4(0.0, -0.2, 0.0));
			cam->crouch = 1;
		}
	}
	else if (cam->crouch == 1)
	{
		j = control_up_down_next(cam, engine->physic_engine->mesh_list);
		if (j == 0.0)
		{
			t_mesh_resize(cam->body, new_vec4(0.0, 0.2, 0.0));
			cam->crouch = 0;
		}
	}
	return (j);
}

t_vec4		forward_backward(t_keyboard *keyboard, t_camera *cam, t_vec4 tmp,
																	t_vec4 save)
{
	if (get_key_state(keyboard, keyboard->key[SDL_SCANCODE_S]) == 1)
	{
		tmp = new_vec4(cam->speed / cam->slowing, 0.0,
													cam->speed / cam->slowing);
		cam->body->force = add_vec4(mult_2_vec4(cam->forward,
										inv_t_vec4(tmp)), new_vec4(0, 0, 0));
		save = new_vec4(cam->body->force.x, cam->body->force.y,
															cam->body->force.z);
	}
	if (get_key_state(keyboard, keyboard->key[SDL_SCANCODE_W]) == 1)
	{
		cam->body->force = add_vec4(mult_2_vec4(cam->forward, tmp),
															new_vec4(0, 0, 0));
		if (save.x != 0 || save.y != 0 || save.z != 0)
			save = add_vec4(divide_vec4_by_float(cam->body->force, 2),
												divide_vec4_by_float(save, 2));
		else
			save = new_vec4(cam->body->force.x, cam->body->force.y,
															cam->body->force.z);
	}
	return (save);
}

t_vec4		left_right(t_keyboard *keyboard, t_camera *cam, t_vec4 tmp,
																	t_vec4 save)
{
	if (get_key_state(keyboard, keyboard->key[SDL_SCANCODE_D]) == 1)
	{
		cam->body->force = add_vec4(mult_2_vec4(cam->right, tmp),
															new_vec4(0, 0, 0));
		if (save.x != 0 || save.y != 0 || save.z != 0)
			save = add_vec4(divide_vec4_by_float(cam->body->force, 2),
												divide_vec4_by_float(save, 2));
		else
			save = new_vec4(cam->body->force.x, cam->body->force.y,
															cam->body->force.z);
	}
	if (get_key_state(keyboard, keyboard->key[SDL_SCANCODE_A]) == 1)
	{
		cam->body->force = add_vec4(mult_2_vec4(inv_t_vec4(cam->right),
													tmp), new_vec4(0, 0, 0));
		if (save.x != 0 || save.y != 0 || save.z != 0)
			save = add_vec4(divide_vec4_by_float(cam->body->force, 2),
												divide_vec4_by_float(save, 2));
		else
			save = new_vec4(cam->body->force.x, cam->body->force.y,
															cam->body->force.z);
	}
	return (save);
}
