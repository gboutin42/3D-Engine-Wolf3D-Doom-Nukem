/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_engine_handle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:35:45 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			t_user_engine_handle_camera(t_engine *engine, t_camera *cam,
											t_window *p_win)
{
	t_mouse		*mouse;
	t_keyboard	*keyboard;

	keyboard = engine->user_engine->keyboard;
	mouse = engine->user_engine->mouse;
	get_t_mouse_info(mouse);
	handle_t_camera_view_by_mouse(cam, mouse);
	SDL_WarpMouseInWindow(p_win->window, WIN_X / 2, WIN_Y / 2);
	if (engine->playing == 2)
		handle_camera_mouvement_by_key(cam, keyboard, engine);
	if (engine->playing == 4)
		move_cam(cam, keyboard);
	compute_t_camera(cam);
}

void			t_user_engine_handle_quit(t_user_engine *user_engine, int *play)
{
	if (get_key_state(user_engine->keyboard, SDL_SCANCODE_ESCAPE))
		*play = 0;
	if (user_engine->event.type == SDL_QUIT)
		*play = 0;
	if (user_engine->event.type == SDL_KEYDOWN
			&& user_engine->event.key.keysym.sym == SDLK_ESCAPE)
		*play = 0;
}

int				t_user_engine_poll_event(t_user_engine *engine)
{
	return (SDL_PollEvent(&(engine->event)));
}
