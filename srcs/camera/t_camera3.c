/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_camera3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:45:02 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:45:03 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_matrix	compute_projection_matrix(t_camera *p_cam)
{
	t_matrix	result;
	float		n;
	float		r;
	float		f;
	float		t;

	result = new_matrix_empty();
	n = p_cam->near;
	r = 1.0 / (tan(degree_to_radius(p_cam->fov / 2.0)));
	f = p_cam->far;
	t = 1.0 / (tan(degree_to_radius(p_cam->fov / 2.0))) / (4.0 / 3.0);
	result.value[0][0] = t;
	result.value[1][1] = r;
	result.value[2][2] = f / (f - n);
	result.value[2][3] = 1.0;
	result.value[3][2] = -(2 * f * n) / (f - n);
	return (result);
}

void		compute_t_camera(t_camera *cam)
{
	cam->view = t_camera_compute_view(cam);
	cam->projection = compute_projection_matrix(cam);
}

t_vec4		apply_t_camera(t_vec4 *src, t_matrix *mat)
{
	t_vec4	result;

	result.x = src->x * mat->value[0][0] + src->y * mat->value[1][0]
								+ src->z * mat->value[2][0] + mat->value[3][0];
	result.y = src->x * mat->value[0][1] + src->y * mat->value[1][1]
								+ src->z * mat->value[2][1] + mat->value[3][1];
	result.z = src->x * mat->value[0][2] + src->y * mat->value[1][2]
								+ src->z * mat->value[2][2] + mat->value[3][2];
	result.w = src->x * mat->value[0][3] + src->y * mat->value[1][3]
								+ src->z * mat->value[2][3] + mat->value[3][3];
	if (result.w != 0)
	{
		result.x /= result.w;
		result.y /= result.w;
		result.z /= -result.w;
	}
	return (result);
}

void		t_camera_change_view(t_camera *cam, float pitch, float yaw)
{
	cam->pitch = clamp_float_value(-89, cam->pitch + pitch, 89);
	cam->yaw += yaw;
	t_camera_look_at(cam);
}

void		move_cam(t_camera *camera, t_keyboard *key)
{
	if (get_key_state(key, key->key[SDL_SCANCODE_W]) == 1)
		camera->pos = add_vec4(camera->pos,
				divide_vec4_by_float(camera->forward, 2.0));
	if (get_key_state(key, key->key[SDL_SCANCODE_S]) == 1)
		camera->pos = add_vec4(camera->pos,
				inv_t_vec4(divide_vec4_by_float(camera->forward, 2.0)));
	if (get_key_state(key, key->key[SDL_SCANCODE_D]) == 1)
		camera->pos = add_vec4(camera->pos,
				divide_vec4_by_float(camera->right, 2.0));
	if (get_key_state(key, key->key[SDL_SCANCODE_A]) == 1)
		camera->pos = add_vec4(camera->pos,
				inv_t_vec4(divide_vec4_by_float(camera->right, 2.0)));
	if (get_key_state(key, key->key[SDL_SCANCODE_SPACE]) == 1)
		camera->pos.y += 0.5;
	if (get_key_state(key, key->key[SDL_SCANCODE_LCTRL]) == 1)
		camera->pos.y -= 0.5;
}
