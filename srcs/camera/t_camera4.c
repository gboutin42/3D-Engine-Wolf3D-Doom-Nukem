/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_camera4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:45:09 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/21 16:46:55 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		delete_t_cam(t_camera dest)
{
	static int	i = 0;

	i++;
	if (dest.body != NULL)
		free_t_mesh(&dest.body);
	free_t_view_port(&dest.view_port);
	delete_t_triangle_list(dest.triangle_color_list);
	delete_t_triangle_list(dest.triangle_texture_list);
	delete_t_color_list(dest.color_list);
	delete_t_color_list(dest.darkness_list);
	delete_t_uv_list(dest.uv_list);
}

void		free_t_cam(t_camera **dest)
{
	delete_t_cam(**dest);
	ft_memdel((void**)dest);
}

void		t_camera_look_at_point(t_camera *cam, t_vec4 targ)
{
	t_vec4	result;

	if (targ.x == cam->pos.x && targ.y == cam->pos.y && targ.z == cam->pos.z)
		return ;
	result = normalize_t_vec4(substract_vec4(cam->pos, targ));
	cam->yaw = radius_to_degree(atan2(result.z, -result.x)) - 90;
	cam->pitch = radius_to_degree(atan2(result.y,
						sqrt(result.x * result.x + result.z * result.z)));
	cam->pitch = clamp_float_value(-89, cam->pitch, 89);
	t_camera_look_at(cam);
}

void		t_camera_look_at(t_camera *cam)
{
	t_vec4	xaxis;
	t_vec4	yaxis;
	t_vec4	zaxis;

	zaxis = normalize_t_vec4(new_vec4(
		cos(degree_to_radius(cam->pitch)) * sin(degree_to_radius(cam->yaw)),
		sin(degree_to_radius(cam->pitch)),
		cos(degree_to_radius(cam->pitch)) * cos(degree_to_radius(cam->yaw))));
	xaxis = normalize_t_vec4(new_vec4(
		sin(degree_to_radius(cam->yaw) - 3.14f / 2.0f), 0,
		cos(degree_to_radius(cam->yaw) - 3.14f / 2.0f)));
	yaxis = normalize_t_vec4(cross_t_vec4(xaxis, zaxis));
	cam->forward = inv_t_vec4(zaxis);
	cam->right = inv_t_vec4(xaxis);
	cam->up = yaxis;
}

t_matrix	t_camera_compute_view(t_camera *cam)
{
	t_matrix	result;

	result = new_matrix();
	result.value[0][0] = cam->right.x;
	result.value[1][0] = cam->right.y;
	result.value[2][0] = cam->right.z;
	result.value[3][0] = -(dot_t_vec4(cam->right, cam->pos));
	result.value[0][1] = cam->up.x;
	result.value[1][1] = cam->up.y;
	result.value[2][1] = cam->up.z;
	result.value[3][1] = -(dot_t_vec4(cam->up, cam->pos));
	result.value[0][2] = cam->forward.x;
	result.value[1][2] = cam->forward.y;
	result.value[2][2] = cam->forward.z;
	result.value[3][2] = -(dot_t_vec4(cam->forward, cam->pos));
	return (result);
}
