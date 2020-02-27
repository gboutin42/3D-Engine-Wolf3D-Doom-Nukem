/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture_cpu.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:15:37 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_triangle	init_st_triangle(t_uv *p_uv, t_triangle *triangle)
{
	t_triangle	result;

	result = new_triangle(
				new_vec4(p_uv->uv.a.x, p_uv->uv.a.y, p_uv->uv.a.z),
				new_vec4(p_uv->uv.b.x, p_uv->uv.b.y, p_uv->uv.b.z),
				new_vec4(p_uv->uv.c.x, p_uv->uv.c.y, p_uv->uv.c.z));
	result.a.x /= triangle->a.w;
	result.a.y /= triangle->a.w;
	result.b.x /= triangle->b.w;
	result.b.y /= triangle->b.w;
	result.c.x /= triangle->c.w;
	result.c.y /= triangle->c.w;
	triangle->a.w = 1.0 / triangle->a.w;
	triangle->b.w = 1.0 / triangle->b.w;
	triangle->c.w = 1.0 / triangle->c.w;
	return (result);
}

t_vec4		calc_w(t_fuck_norme data)
{
	t_vec4		result;

	result = new_vec4(
		edge_t_vec4(data.triangle.b, data.triangle.c, data.pixel_sample)
																/ data.area,
		edge_t_vec4(data.triangle.c, data.triangle.a, data.pixel_sample)
																/ data.area,
		edge_t_vec4(data.triangle.a, data.triangle.b, data.pixel_sample)
																/ data.area);
	return (result);
}

void		draw_triangle_texture_cpu_next(t_view_port *p_view_port, t_uv *p_uv,
															t_fuck_norme data)
{
	data.pixel_sample = new_vec4(data.x, data.y, 0);
	data.w = calc_w(data);
	if (data.w.x >= 0 && data.w.y >= 0 && data.w.z >= 0)
	{
		data.z = 1 / ((data.triangle.a.w * data.w.x)
			+ (data.triangle.b.w * data.w.y) + (data.triangle.c.w * data.w.z));
		if (data.z <= p_view_port->depth_buffer[data.pixel_index])
		{
			data.s = (data.w.x * data.st.a.x + data.w.y * data.st.b.x + data.w.z
							* data.st.c.x) * data.z * p_uv->texture->surface->w;
			data.t = (data.w.x * data.st.a.y + data.w.y * data.st.b.y + data.w.z
							* data.st.c.y) * data.z * p_uv->texture->surface->h;
			data.rgb = get_pixel_color(p_uv->texture, data.s, data.t);
			if (data.rgb.a == 1.0)
			{
				p_view_port->depth_buffer[data.pixel_index] = data.z;
				draw_pixel(p_view_port->window,
					(int)(data.pixel_sample.x + p_view_port->pos.x),
					(int)(data.pixel_sample.y + p_view_port->pos.y), data.rgb);
			}
		}
	}
}

void		draw_triangle_texture_cpu(t_view_port *p_view_port,
											t_triangle *p_triangle, t_uv *p_uv)
{
	t_fuck_norme	data;

	data.triangle.a = convert_opengl_to_vec4(p_view_port, p_triangle->a);
	data.triangle.b = convert_opengl_to_vec4(p_view_port, p_triangle->b);
	data.triangle.c = convert_opengl_to_vec4(p_view_port, p_triangle->c);
	data.st = init_st_triangle(p_uv, &data.triangle);
	t_triangle_get_min_max_value(&data.triangle, &data.min, &data.max);
	get_min_max_draw_triangle(p_view_port, &data.min, &data.max);
	data.area = edge_t_vec4(data.triangle.a, data.triangle.b,
															data.triangle.c);
	data.y = data.min.y - 1;
	while (++data.y <= data.max.y)
	{
		data.pixel_index = (int)(data.min.x) + (data.y * p_view_port->size.x);
		data.x = data.min.x - 1;
		while (++data.x <= data.max.x)
		{
			draw_triangle_texture_cpu_next(p_view_port, p_uv, data);
			data.pixel_index++;
		}
	}
}
