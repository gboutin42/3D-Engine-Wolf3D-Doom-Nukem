/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:16:00 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		draw_pixel(t_window *p_win, int x, int y, t_color color)
{
	if (p_win->color_data[x + y * p_win->size_x].a != 0 && color.a != 1)
		color = fuze_t_color(color, p_win->color_data[x + y * p_win->size_x]);
	p_win->color_data[x + y * p_win->size_x] = color;
}
