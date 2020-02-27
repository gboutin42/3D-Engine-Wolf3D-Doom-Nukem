/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:28:51 by spuisais          #+#    #+#             */
/*   Updated: 2020/02/14 11:59:00 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	create_minimap(t_engine *engine)
{
	t_camera	*main_camera;

	main_camera = t_camera_list_get(engine->visual_engine->camera_list, 0);
	t_engine_place_camera(engine, 0, new_vec4(5.0, 5.0, 0.0));
	t_camera_look_at_point(main_camera, new_vec4(0, 0, 0));
	t_engine_add_camera(engine, new_camera(engine->win, new_vec4(0.0, 0.0, 0.0),
												70, create_vec2(NEAR, FAR)));
	resize_t_view_port(t_camera_list_get(
		engine->visual_engine->camera_list, 1)->view_port,
										create_vec2_int(300, 240));
	move_t_view_port(t_camera_list_get(
		engine->visual_engine->camera_list, 1)->view_port,
										create_vec2_int(WIN_X - 300, 0));
}

void	draw_minimap(t_engine *engine)
{
	t_camera	*cam;

	t_engine_place_camera(engine, 1, add_vec4(t_camera_list_get(
		engine->visual_engine->camera_list, 0)->pos,
		new_vec4(0.0, 7.0, 0.0)));
	t_camera_look_at_point(t_camera_list_get(
		engine->visual_engine->camera_list, 1),
		t_camera_list_get(engine->visual_engine->camera_list, 0)->pos);
	cam = t_camera_list_get(engine->visual_engine->camera_list, 1);
	compute_t_camera(cam);
	draw_triangle_from_camera_on_screen(cam);
}
