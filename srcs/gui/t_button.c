/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_button.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:46:31 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:00 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		t_mouse_state(t_mouse *mouse)
{
	if (get_mouse_state(mouse, MOUSE_LEFT) == BOOL_TRUE)
	{
		mouse->clicked_left = BOOL_TRUE;
		return (1);
	}
	else if (get_mouse_state(mouse, MOUSE_LEFT) == BOOL_FALSE
											&& mouse->clicked_left == BOOL_TRUE)
	{
		mouse->clicked_left = BOOL_FALSE;
		return (2);
	}
	else if (get_mouse_state(mouse, MOUSE_RIGHT) == BOOL_TRUE)
	{
		mouse->clicked_right = BOOL_TRUE;
		return (-1);
	}
	else if (get_mouse_state(mouse, MOUSE_RIGHT) == BOOL_FALSE
										&& mouse->clicked_right == BOOL_TRUE)
	{
		mouse->clicked_right = BOOL_FALSE;
		return (-2);
	}
	else
		return (0);
}

int		t_key_state(t_keyboard *key)
{
	if (get_key_state(key, MOUSE_LEFT) == BOOL_TRUE)
	{
		key->clicked = BOOL_TRUE;
		return (1);
	}
	else if (get_key_state(key, MOUSE_LEFT) == BOOL_FALSE
												&& key->clicked == BOOL_TRUE)
	{
		key->clicked = BOOL_FALSE;
		return (2);
	}
	else
		return (0);
}
