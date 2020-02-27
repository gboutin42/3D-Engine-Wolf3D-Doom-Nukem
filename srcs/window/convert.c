/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:51:39 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:51:40 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_vec4		convert_screen_to_opengl(t_view_port *p_view_port,
											t_vec4 source)
{
	t_vec4 result;

	result.x = source.x / ((float)(p_view_port->size.x) / 2.0) - 1.0f;
	result.y = -(source.y / ((float)(p_view_port->size.y) / 2.0) - 1.0f);
	result.z = source.z;
	return (result);
}

t_vec4		convert_opengl_to_vec4(t_view_port *p_view_port,
											t_vec4 source)
{
	t_vec4 result;

	result.x = (source.x + 1.0f) * ((float)(p_view_port->size.x) / 2.0);
	result.y = (-(source.y) + 1.0f) * ((float)(p_view_port->size.y) / 2.0);
	result.z = source.z;
	return (result);
}

float		degree_to_radius(float angle)
{
	return ((float)(((float)angle) * M_PI / (float)180));
}

float		radius_to_degree(float radian)
{
	return ((float)((float)(radian * 180) / M_PI));
}

t_uv		convert_t_uv_to_texture(t_uv *source)
{
	t_uv	result;

	result = *source;
	result.uv.a.y = 1 - result.uv.a.y;
	result.uv.b.y = 1 - result.uv.b.y;
	result.uv.c.y = 1 - result.uv.c.y;
	return (result);
}
