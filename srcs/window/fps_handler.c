/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:51:46 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:51:46 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		check_frame(t_engine *engine)
{
	static int		nb_frame = 0;
	static int		beginsecond = 0;
	int				frame_actual;
	static Uint32	framestart;

	frame_actual = SDL_GetTicks();
	if (beginsecond == 0)
		beginsecond = frame_actual;
	if (frame_actual - beginsecond > 1000)
	{
		engine->tick++;
		ft_putstr("nb_frame = ");
		ft_putnbr(nb_frame);
		write(1, "\n", 1);
		nb_frame = 0;
		beginsecond = 0;
	}
	else
		nb_frame++;
	framestart = SDL_GetTicks();
}
