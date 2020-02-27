/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 11:12:33 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_engine		*init_cam(t_engine *engine, t_window *win)
{
	t_camera	*main_camera;

	engine = initialize_t_engine(win);
	main_camera = t_camera_list_get(engine->visual_engine->camera_list, 0);
	t_engine_place_camera(engine, 0, new_vec4(5.0, 5.0, 0.0));
	t_camera_look_at_point(main_camera, new_vec4(0, 0, 0));
	t_engine_add_camera(engine, new_camera(win,
			new_vec4(0.0, 0.0, 0.0), 70, create_vec2(NEAR, FAR)));
	resize_t_view_port(
		t_camera_list_get(engine->visual_engine->camera_list, 1)->view_port,
		create_vec2_int(300, 240));
	move_t_view_port(
		t_camera_list_get(engine->visual_engine->camera_list, 1)->view_port,
		create_vec2_int(WIN_X - 300, 0));
	return (engine);
}
