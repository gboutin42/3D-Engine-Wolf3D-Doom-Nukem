/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mouse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 11:10:02 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_mouse	new_mouse(void)
{
	t_mouse	result;

	result.old_pos = create_vec2_int(-1, -1);
	result.pos = create_vec2_int(-1, -1);
	result.rel_pos = create_vec2_int(0, 0);
	result.button[MOUSE_LEFT] = BOOL_FALSE;
	result.button[MOUSE_RIGHT] = BOOL_FALSE;
	result.button[MOUSE_MIDDLE] = BOOL_FALSE;
	result.clicked_left = BOOL_FALSE;
	result.clicked_right = BOOL_FALSE;
	result.sens = 10;
	return (result);
}

t_mouse	*initialize_t_mouse(void)
{
	t_mouse	*result;

	if (!(result = (t_mouse *)ft_memalloc(sizeof(t_mouse))))
		return (NULL);
	*result = new_mouse();
	return (result);
}

void	get_t_mouse_info(t_mouse *mouse)
{
	Uint32 mousestate;

	mouse->old_pos = mouse->pos;
	mousestate = SDL_GetMouseState(&(mouse->pos.x), &(mouse->pos.y));
	if (mouse->old_pos.x != -1)
		mouse->rel_pos = create_vec2_int((mouse->pos.x - WIN_X / 2),
											(mouse->pos.y - WIN_Y / 2));
	if (mousestate & SDL_BUTTON(SDL_BUTTON_LEFT))
		mouse->button[MOUSE_LEFT] = BOOL_TRUE;
	else
		mouse->button[MOUSE_LEFT] = BOOL_FALSE;
	if (mousestate & SDL_BUTTON(SDL_BUTTON_RIGHT))
		mouse->button[MOUSE_RIGHT] = BOOL_TRUE;
	else
		mouse->button[MOUSE_RIGHT] = BOOL_FALSE;
	if (mousestate & SDL_BUTTON(SDL_BUTTON_MIDDLE))
		mouse->button[MOUSE_MIDDLE] = BOOL_TRUE;
	else
		mouse->button[MOUSE_MIDDLE] = BOOL_FALSE;
}

int		get_mouse_state(t_mouse *mouse, int type)
{
	if (type < 0 || type > 3)
		return (-1);
	return (mouse->button[type]);
}
