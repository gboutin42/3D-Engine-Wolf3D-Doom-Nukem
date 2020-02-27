/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:09:52 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_user_engine	new_user_engine(void)
{
	t_user_engine	result;

	result.mouse = initialize_t_mouse();
	result.keyboard = initialize_t_keyboard();
	result.player = NULL;
	return (result);
}

t_user_engine	*initialize_t_user_engine(void)
{
	t_user_engine	*result;

	if (!(result = (t_user_engine *)ft_memalloc(sizeof(t_user_engine))))
		return (NULL);
	*result = new_user_engine();
	return (result);
}

void			delete_t_user_engine(t_user_engine dest)
{
	ft_memdel((void**)&dest.player);
	ft_memdel((void**)&dest.mouse);
	ft_memdel((void**)&dest.keyboard);
}

void			free_t_user_engine(t_user_engine **dest)
{
	delete_t_user_engine(**dest);
	ft_memdel((void**)dest);
}
