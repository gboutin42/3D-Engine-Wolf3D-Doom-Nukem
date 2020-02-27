/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_engine_next.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:37:15 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			t_visual_engine_render_camera(t_visual_engine *engine)
{
	int			i;
	t_camera	*cam;

	i = 0;
	while (i < engine->camera_list->size)
	{
		cam = t_camera_list_get(engine->camera_list, i);
		compute_t_camera(cam);
		draw_triangle_from_camera_on_screen(cam);
		i++;
	}
}

void			t_visual_engine_render_first_camera(t_visual_engine *engine)
{
	t_camera *cam;

	cam = t_camera_list_get(engine->camera_list, 0);
	compute_t_camera(cam);
	draw_triangle_from_camera_on_screen(cam);
}

void			t_visual_engine_prepare_camera(t_visual_engine *engine)
{
	int			i;

	i = 0;
	while (i < engine->camera_list->size)
	{
		clean_t_camera(t_camera_list_get(engine->camera_list, i));
		i++;
	}
}

void			t_visual_engine_add_camera(t_visual_engine *engine,
															t_camera new_camera)
{
	t_camera_list_push_back(engine->camera_list, new_camera);
}

t_camera		*t_visual_engine_get_main_camera(t_visual_engine *engine)
{
	t_camera *result;

	result = t_camera_list_get(engine->camera_list, engine->main_camera);
	return (result);
}
