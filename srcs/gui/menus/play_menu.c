/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <spuisais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:46:35 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/25 11:22:38 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	synopsis_menu(t_engine *engine)
{
	t_mouse			*mou;
	t_vec2_int		pos;

	mou = engine->user_engine->mouse;
	get_t_mouse_info(mou);
	pos = create_vec2_int(mou->pos.x * 100 / WIN_X, mou->pos.y * 100 / WIN_Y);
	if (t_mouse_state(mou) == 2)
		if ((pos.x > 85 && pos.x < 96) && (pos.y > 83 && pos.y < 96))
			engine->playing = 2;
}

void	open_scenario_or_editor(t_vec2_int pos, t_engine *engine, char **path)
{
	if (pos.x > 37 && pos.x < 61)
	{
		if (pos.y > 61 && pos.y < 69)
		{
			engine->playing = 4;
			*path = ft_strdup("ressources/map/editing_map.map");
		}
		if (pos.y > 71 && pos.y < 79)
			engine->menu_nbr = 0;
	}
	if (pos.x > 6 && pos.x < 24)
	{
		if (pos.y > 29 && pos.y < 37)
		{
			engine->menu_nbr = 17;
			*path = ft_strdup("ressources/map/chapter1.map");
		}
		if (pos.y > 39 && pos.y < 47)
		{
			engine->playing = 2;
			*path = ft_strdup("ressources/map/chapter2.map");
		}
	}
}

void	open_save2(t_vec2_int pos, int *play, char **path)
{
	if (pos.y > 59 && pos.y < 67)
	{
		*play = 2;
		*path = ft_strdup("ressources/map/save4.map");
	}
	if (pos.y > 69 && pos.y < 77)
	{
		*play = 2;
		*path = ft_strdup("ressources/map/save5.map");
	}
}

void	open_save(t_vec2_int pos, int *play, char **path)
{
	if (pos.x > 82 && pos.x < 95)
	{
		if (pos.y > 29 && pos.y < 37)
		{
			*play = 2;
			*path = ft_strdup("ressources/map/save1.map");
		}
		if (pos.y > 39 && pos.y < 47)
		{
			*play = 2;
			*path = ft_strdup("ressources/map/save2.map");
		}
		if (pos.y > 49 && pos.y < 57)
		{
			*play = 2;
			*path = ft_strdup("ressources/map/save3.map");
		}
		open_save2(pos, play, path);
	}
}

void	play_menu(t_camera *main_camera, t_engine *engine, int *play)
{
	t_mouse			*mou;
	t_vec2_int		pos;
	char			*path;

	mou = engine->user_engine->mouse;
	get_t_mouse_info(mou);
	pos = create_vec2_int(mou->pos.x * 100 / WIN_X, mou->pos.y * 100 / WIN_Y);
	if (t_mouse_state(mou) == 2)
	{
		open_scenario_or_editor(pos, engine, &path);
		open_save(pos, play, &path);
		Mix_PlayChannel(-1, engine->sound_engine->sounds[0], 0);
	}
	if (*play == 4 || *play == 2 || engine->menu_nbr == 17)
	{
		if (!path)
			error_exit(-71, "Couldn't load map, exiting.");
		check_map(path);
		load_map(main_camera, engine, path);
		link_camera_to_mesh(engine, 0, t_engine_get_mesh(engine, 0));
		ft_memdel((void**)&path);
	}
}
