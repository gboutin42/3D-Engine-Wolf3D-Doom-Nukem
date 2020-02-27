/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_t_gui.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:22:15 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:00 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	delete_t_letter(t_letter *dest)
{
	SDL_FreeSurface(dest->font);
	ft_memdel((void**)&dest->let->surface);
	ft_memdel((void**)&dest->let);
}

void	free_t_letter(t_letter **dest)
{
	delete_t_letter(*dest);
	ft_memdel((void**)dest);
}

void	delete_t_gui(t_gui dest)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 94)
		free_t_letter(&dest.letter[i]);
	i = -1;
	while (++i < 20)
		free_t_texture(&dest.menu[i]);
	i = -1;
	while (++i < 11)
		free_t_texture(&dest.text_weap[i]);
	i = -1;
	while (++i < 6)
		free_t_texture(&dest.text_am[i]);
	i = -1;
	while (++i < 25 && (j = -1) == -1)
	{
		while (++j < dest.len[i])
			ft_strdel(&(dest.path[i][j]));
		ft_memdel((void**)&dest.path[i]);
	}
	free_t_texture(&dest.skybox);
	ft_memdel((void**)dest.letter);
	ft_memdel((void**)&dest.menu);
}

void	free_t_gui(t_gui *dest)
{
	delete_t_gui(*dest);
	ft_memdel((void**)dest);
}
