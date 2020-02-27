/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:01:07 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/21 16:41:35 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_engine	new_engine(t_window *p_window)
{
	t_engine	result;

	result.win = p_window;
	result.playing = 1;
	result.menu_nbr = 0;
	result.display_skybox = 0;
	result.tick = 0;
	result.difficulty = 1.0;
	result.visual_engine = initialize_t_visual_engine(p_window);
	result.physic_engine = initialize_t_physic_engine();
	result.user_engine = initialize_t_user_engine();
	result.sound_engine = initialize_t_sound_engine();
	return (result);
}

t_engine	*initialize_t_engine(t_window *p_window)
{
	t_engine	*result;

	if (!(result = (t_engine *)ft_memalloc(sizeof(t_engine))))
		return (NULL);
	*result = new_engine(p_window);
	return (result);
}

void		delete_t_engine(t_engine *dest)
{
	free_t_window(&dest->win);
	free_t_visual_engine(&(dest)->visual_engine);
	free_t_physic_engine(&(dest)->physic_engine);
	free_t_user_engine(&(dest)->user_engine);
	free_t_sound_engine(&(dest)->sound_engine);
}

void		free_t_engine(t_engine **dest)
{
	delete_t_engine(*dest);
	ft_memdel((void**)dest);
}

void		t_engine_apply_physic(t_engine *engine)
{
	t_p_engine_comp_vert_world(engine->physic_engine);
	t_physic_engine_apply_force(engine);
}
