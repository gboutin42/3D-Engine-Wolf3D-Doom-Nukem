/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_camera2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:44:55 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:44:56 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		handle_t_camera_view_by_mouse(t_camera *cam, t_mouse *p_mouse)
{
	float	delta_pitch;
	float	delta_yaw;

	delta_pitch = -(p_mouse->rel_pos.x / p_mouse->sens);
	delta_yaw = p_mouse->rel_pos.y / p_mouse->sens;
	t_camera_change_view(cam, delta_yaw, delta_pitch);
}

void		draw_triangle_from_camera_on_screen(t_camera *p_cam)
{
	if (p_cam->triangle_color_list.size > 0)
		multithreading_draw_triangle_color_cpu(p_cam->view_port,
						&(p_cam->triangle_color_list), &(p_cam->color_list));
	if (p_cam->triangle_texture_list.size > 0)
		multithreading_draw_triangle_texture_cpu(p_cam->view_port,
						&(p_cam->triangle_texture_list), &(p_cam->uv_list));
}

void		clean_t_camera(t_camera *camera)
{
	clean_t_triangle_list(&(camera->triangle_color_list));
	(&(camera->color_list))->size = 0;
	clean_t_triangle_list(&(camera->triangle_texture_list));
	(&(camera->darkness_list))->size = 0;
	clean_t_uv_list(&(camera->uv_list));
	t_view_port_clear_buffers(camera->view_port);
}

void		link_camera_to_mesh(t_engine *engine, int index, t_mesh *mesh)
{
	t_camera	*camera;

	camera = t_camera_list_get(engine->visual_engine->camera_list, index);
	if (camera->body != NULL)
		camera->body->camera = NULL;
	camera->body = mesh;
	if (mesh != NULL)
		mesh->camera = camera;
}

void		move_camera(t_camera *camera, t_engine *engine, float j)
{
	if (camera->body->no_hitbox == 1 && camera->body->is_visible == 0)
		t_mesh_move(camera->body, camera->body->force);
	else if (can_move(camera->body, engine) == BOOL_TRUE)
		t_mesh_move(camera->body, camera->body->force);
	t_physic_engine_apply_force(engine);
	camera->pos = add_vec4(camera->pos, camera->body->force);
	camera->pos = add_vec4(camera->body->pos,
					new_vec4(0.15, 0.45 - j, 0.15));
	engine->user_engine->player->hitbox.pos = camera->pos;
}
