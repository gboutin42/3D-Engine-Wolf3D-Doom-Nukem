/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_system.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:00:14 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 16:00:15 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_SYSTEM_H
# define WOLF3D_SYSTEM_H

# include "wolf3d_define.h"
# include "wolf3d_vector.h"

typedef struct	s_mouse
{
	t_vec2_int	old_pos;
	t_vec2_int	pos;
	t_vec2_int	rel_pos;
	int			button[MOUSE_BUTTON];
	char		clicked_left;
	char		clicked_right;
	int			sens;
}				t_mouse;

t_mouse			new_mouse();
t_mouse			*initialize_t_mouse();
void			get_t_mouse_info(t_mouse *mouse);
void			print_t_mouse(t_mouse *mouse);
int				get_mouse_state(t_mouse *mouse, int type);

typedef struct	s_keyboard
{
	int			key[232];
	char		clicked;
	int			i;
	const Uint8	*state;
}				t_keyboard;

t_keyboard		new_keyboard();
t_keyboard		*initialize_t_keyboard();
int				get_key_state(t_keyboard *keyboard, int scan_code);
void			reset_key_state(t_keyboard *keyboard, int scan_code);

#endif
