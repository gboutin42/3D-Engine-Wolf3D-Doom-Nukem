/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:51:57 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:51:57 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		start_sdl(void)
{
	unsigned int seed;

	seed = 1493368;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		error_exit(ft_atoi(SDL_GetError()), "Erreur SDL_Init");
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
						SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	srand(seed);
}

void		prepare_screen(t_window *p_win, t_color color)
{
	glClearColor((GLclampf)color.r, (GLclampf)color.g, (GLclampf)color.b, 1.0f);
	window_handler_clear_buffers(p_win);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void		render_screen(t_engine *engine)
{
	check_frame(engine);
	draw_buffer_opengl(engine->win, engine->win->color_data);
	SDL_GL_SwapWindow(engine->win->window);
}

int			is_point_in_screen(t_window *p_win, t_vec4 p_point)
{
	if (p_point.x < 0 || p_point.x >= p_win->size_x ||
		p_point.y < 0 || p_point.y >= p_win->size_y)
		return (0);
	return (1);
}

int			is_t_triangle_in_screen(t_window *p_win, t_triangle *p_triangle)
{
	if (p_triangle->a.x < 0 && p_triangle->b.x < 0 && p_triangle->c.x < 0)
		return (0);
	if (p_triangle->a.x >= p_win->size_x && p_triangle->b.x >= p_win->size_x
		&& p_triangle->c.x >= p_win->size_x)
		return (0);
	if (p_triangle->a.y < 0 && p_triangle->b.y < 0 && p_triangle->c.y < 0)
		return (0);
	if (p_triangle->a.y >= p_win->size_y && p_triangle->b.y >= p_win->size_y
		&& p_triangle->c.y >= p_win->size_y)
		return (0);
	return (1);
}
