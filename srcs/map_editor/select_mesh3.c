/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_mesh3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:48:18 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:48:18 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_mesh			create_mesh_plane_enemy(int index, t_mesh mesh)
{
	t_mesh	ret;

	ret = mesh;
	if (index == 20)
	{
		ret.name = "plane";
		ret.size = new_vec4(1.0, 0.0, 1.0);
		ret.primitive = 0;
		ret.collectible = 0;
		ret.rotation = new_vec4(0.0, 0.0, 0.0);
		ret.hp = -1;
		ret.kinetic = 0.0;
	}
	else if (index == 21)
	{
		ret.name = "Enemy";
		ret.size = new_vec4(0.3, 0.5, 0.3);
		ret.primitive = 1;
		ret.collectible = 0;
		ret.rotation = new_vec4(0.0, 0.0, 0.0);
		ret.hp = 50;
		ret.kinetic = 0.0;
	}
	return (ret);
}

t_mesh			create_mesh_window_player(int index, t_mesh mesh)
{
	t_mesh	ret;

	ret = mesh;
	if (index == 22)
	{
		ret.name = "window";
		ret.size = new_vec4(2.0, 2.0, 0.3);
		ret.primitive = 1;
		ret.collectible = 0;
		ret.rotation = new_vec4(0.0, 0.0, 0.0);
		ret.hp = -1;
		ret.kinetic = 0.0;
	}
	else if (index == 23)
	{
		ret.name = "Player";
		ret.size = new_vec4(0.3, 0.5, 0.3);
		ret.primitive = -1;
		ret.collectible = 0;
		ret.rotation = new_vec4(0.0, 0.0, 0.0);
		ret.hp = 100;
		ret.kinetic = 100.0;
	}
	return (ret);
}

t_mesh			create_mesh_end(int index, t_mesh mesh)
{
	t_mesh	ret;

	ret = mesh;
	if (index == 24)
	{
		ret.name = "end";
		ret.size = new_vec4(0.3, 0.1, 0.3);
		ret.primitive = 1;
		ret.collectible = 0;
		ret.rotation = new_vec4(0.0, 0.0, 0.0);
		ret.hp = -1;
		ret.kinetic = 0.0;
	}
	return (ret);
}

void			select_texture_next(t_keyboard *key, t_gui *gui,
															int *i, int *press)
{
	if (get_key_state(key, key->key[SDL_SCANCODE_RIGHTBRACKET]) == 1
																&& *press == 0)
	{
		(*i)++;
		if (*i >= gui->len[key->i])
			*i = 0;
		*press = 1;
	}
	if (get_key_state(key, key->key[SDL_SCANCODE_LEFTBRACKET]) == 1
																&& *press == 0)
	{
		(*i)--;
		if (*i < 0)
			*i = gui->len[key->i] - 1;
		*press = 1;
	}
	else if (get_key_state(key, key->key[SDL_SCANCODE_RIGHTBRACKET]) == 0
				&& get_key_state(key, key->key[SDL_SCANCODE_LEFTBRACKET]) == 0)
		*press = 0;
}

int				select_texture(t_keyboard *key, t_gui *gui)
{
	static int	tmp = -9;
	static int	press = 0;
	static int	i = 0;

	if (tmp == -9)
		tmp = key->i;
	if (tmp != key->i)
	{
		tmp = key->i;
		i = 0;
	}
	select_texture_next(key, gui, &i, &press);
	return (i);
}
