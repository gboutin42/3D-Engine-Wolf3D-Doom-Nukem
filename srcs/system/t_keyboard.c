/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_keyboard.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:15:30 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		init_keyboard_letter(t_keyboard *result)
{
	result->key[SDL_SCANCODE_W] = SDL_SCANCODE_W;
	result->key[SDL_SCANCODE_A] = SDL_SCANCODE_A;
	result->key[SDL_SCANCODE_S] = SDL_SCANCODE_S;
	result->key[SDL_SCANCODE_D] = SDL_SCANCODE_D;
	result->key[SDL_SCANCODE_F] = SDL_SCANCODE_F;
	result->key[SDL_SCANCODE_I] = SDL_SCANCODE_I;
	result->key[SDL_SCANCODE_R] = SDL_SCANCODE_R;
	result->key[SDL_SCANCODE_L] = SDL_SCANCODE_L;
	result->key[SDL_SCANCODE_1] = SDL_SCANCODE_1;
	result->key[SDL_SCANCODE_2] = SDL_SCANCODE_2;
	result->key[SDL_SCANCODE_3] = SDL_SCANCODE_3;
	result->key[SDL_SCANCODE_4] = SDL_SCANCODE_4;
	result->key[SDL_SCANCODE_5] = SDL_SCANCODE_5;
	result->key[SDL_SCANCODE_6] = SDL_SCANCODE_6;
	result->key[SDL_SCANCODE_B] = SDL_SCANCODE_B;
}

t_keyboard	new_keyboard(void)
{
	t_keyboard	result;

	init_keyboard_letter(&result);
	result.key[SDL_SCANCODE_LCTRL] = SDL_SCANCODE_LCTRL;
	result.key[SDL_SCANCODE_LSHIFT] = SDL_SCANCODE_LSHIFT;
	result.key[SDL_SCANCODE_SPACE] = SDL_SCANCODE_SPACE;
	result.key[SDL_SCANCODE_Z] = SDL_SCANCODE_Z;
	result.key[SDL_SCANCODE_PERIOD] = SDL_SCANCODE_PERIOD;
	result.key[SDL_SCANCODE_COMMA] = SDL_SCANCODE_COMMA;
	result.key[SDL_SCANCODE_LEFT] = SDL_SCANCODE_LEFT;
	result.key[SDL_SCANCODE_RIGHT] = SDL_SCANCODE_RIGHT;
	result.key[SDL_SCANCODE_UP] = SDL_SCANCODE_UP;
	result.key[SDL_SCANCODE_DOWN] = SDL_SCANCODE_DOWN;
	result.key[SDL_SCANCODE_EQUALS] = SDL_SCANCODE_EQUALS;
	result.key[SDL_SCANCODE_MINUS] = SDL_SCANCODE_MINUS;
	result.key[SDL_SCANCODE_RIGHTBRACKET] = SDL_SCANCODE_RIGHTBRACKET;
	result.key[SDL_SCANCODE_LEFTBRACKET] = SDL_SCANCODE_LEFTBRACKET;
	result.state = SDL_GetKeyboardState(NULL);
	result.i = 0;
	return (result);
}

t_keyboard	*initialize_t_keyboard(void)
{
	t_keyboard	*result;

	if (!(result = (t_keyboard *)ft_memalloc(sizeof(t_keyboard))))
		return (NULL);
	*result = new_keyboard();
	return (result);
}

int			get_key_state(t_keyboard *keyboard, int scan_code)
{
	if (keyboard->state[scan_code] != 0)
		return (1);
	return (0);
}

void		reset_key_state(t_keyboard *keyboard, int scan_code)
{
	((Uint8 *)(keyboard->state))[scan_code] = 0;
}
