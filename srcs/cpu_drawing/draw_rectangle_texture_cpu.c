/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rectangle_texture_cpu.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:16:48 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_triangle(t_triangle_list *tri_list, t_rectangle p_rec)
{
	t_triangle	tri;

	tri = new_triangle(new_vec4(p_rec.pos.x, p_rec.pos.y, 1.0),
				new_vec4(p_rec.pos.x + p_rec.size.x, p_rec.pos.y, 1.0),
				new_vec4(p_rec.pos.x, p_rec.pos.y + p_rec.size.y, 1.0));
	t_triangle_list_push_back(tri_list, tri);
	tri = new_triangle(
		new_vec4(p_rec.pos.x + p_rec.size.x,
				p_rec.pos.y + p_rec.size.y, 1.0),
				new_vec4(p_rec.pos.x + p_rec.size.x, p_rec.pos.y, 1.0),
				new_vec4(p_rec.pos.x, p_rec.pos.y + p_rec.size.y, 1.0));
	t_triangle_list_push_back(tri_list, tri);
}

void	draw_rectangle_texture_cpu(t_view_port *p_view_port, t_rectangle p_rec,
														t_texture *p_texture)
{
	t_triangle_list	tri_list;
	t_uv_list		uv_list;
	t_uv			uv;

	uv_list = new_uv_list();
	tri_list = new_triangle_list();
	init_triangle(&tri_list, p_rec);
	uv = new_uv(new_triangle(new_vec4(0, 1, 0),
			new_vec4(1, 1, 0), new_vec4(0, 0, 0)), p_texture);
	t_uv_list_push_back(&uv_list, uv);
	uv = new_uv(new_triangle(new_vec4(1, 0, 0),
			new_vec4(1, 1, 0), new_vec4(0, 0, 0)), p_texture);
	t_uv_list_push_back(&uv_list, uv);
	multithreading_draw_triangle_texture_cpu(p_view_port, &tri_list, &uv_list);
	delete_t_uv_list(uv_list);
	delete_t_triangle_list(tri_list);
}
