/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playing_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <spuisais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:49:17 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/19 14:57:27 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	display_title_screen(t_camera *camera, t_gui *gui, t_engine *engine,
																	t_mesh mesh)
{
	t_rectangle		rec;

	mesh.pos = camera->pos;
	rec = new_rectangle(create_vec2(-1, 1), create_vec2(2, -2));
	draw_rectangle_texture_cpu(camera->view_port, rec,
					gui->menu[engine->menu_nbr]);
}

void	game_playing(t_camera *camera, t_gui *gui, t_engine *engine,
																	t_mesh mesh)
{
	if (engine->display_skybox)
	{
		mesh.pos = camera->pos;
		draw_t_mesh(camera, &mesh);
		t_engine_render_camera(engine);
	}
	t_engine_apply_physic(engine);
	t_engine_handle_camera(engine, engine->win);
	t_engine_prepare_camera(engine);
	t_engine_draw_mesh(engine);
	t_engine_render_camera(engine);
	player_action(camera, engine->user_engine->keyboard,
										engine, gui->text_weap);
	enemy_look(engine);
	enemy_shoot(engine);
	enemy_boss_shoot(engine);
	enemy_boss_spawn(engine);
	drawing_front_hp(camera, engine->user_engine->player);
	drawing_front_mun(camera, gui->text_am, engine->user_engine->player);
	drawing_front_weapons(camera, gui->text_weap,
								engine->user_engine->player);
	draw_minimap(engine);
	print_info_bar(camera, engine->user_engine->player, gui);
}

void	game_paused(t_camera *camera, t_gui *gui, t_engine *engine, t_mesh mesh)
{
	t_rectangle		rec;

	mesh.pos = camera->pos;
	rec = new_rectangle(create_vec2(-1, 1), create_vec2(2, -2));
	t_engine_draw_mesh(engine);
	t_engine_render_camera(engine);
	t_view_port_clear_buffers(camera->view_port);
	draw_rectangle_texture_cpu(camera->view_port, rec,
									gui->menu[engine->menu_nbr]);
}

void	level_editing(t_camera *camera, t_gui *gui, t_engine *engine,
																	t_mesh mesh)
{
	t_mesh_editing	mesh_editing;

	mesh.pos = camera->pos;
	draw_t_mesh(camera, &mesh);
	t_engine_render_camera(engine);
	t_engine_apply_physic(engine);
	t_engine_handle_camera(engine, engine->win);
	t_engine_prepare_camera(engine);
	t_engine_draw_mesh(engine);
	t_engine_render_camera(engine);
	mesh_editing = select_mesh(engine->user_engine->keyboard,
		engine->user_engine->player->camera->pos,
		gui);
	map_editor(camera, gui, engine, mesh_editing);
}

void	level_editing_paused(t_camera *camera, t_gui *gui, t_engine *engine,
																	t_mesh mesh)
{
	t_rectangle		rec;

	mesh.pos = camera->pos;
	rec = new_rectangle(create_vec2(-1, 1), create_vec2(2, -2));
	t_engine_draw_mesh(engine);
	t_engine_render_camera(engine);
	t_view_port_clear_buffers(camera->view_port);
	draw_rectangle_texture_cpu(camera->view_port, rec,
									gui->menu[engine->menu_nbr]);
	if (engine->menu_nbr == 14)
		print_set_player(camera, gui, engine);
	else if (engine->menu_nbr == 15)
		print_set_weapon(camera, gui, engine);
}
