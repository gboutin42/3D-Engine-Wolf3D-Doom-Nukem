/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_opengl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:19:04 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:00 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_buffer_opengl(t_window *win, t_color *color_data)
{
	int	screen_len;

	screen_len = win->size_x * win->size_y;
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GLfloat) * 4 * screen_len,
									color_data);
	glUseProgram(win->program_color);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, win->vertex_fixed_buffer);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, win->color_fixed_buffer);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, NULL);
	glDrawArrays(GL_POINTS, 0, screen_len);
}
