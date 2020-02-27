/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture_map_editor.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:46:55 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:46:57 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	load_texture_key_elevator(t_gui *gui)
{
	gui->len[6] = 1;
	if (!(gui->path[6] = (char**)ft_memalloc(sizeof(char*) * 1)))
		error_exit(2, "error ft_memalloc");
	gui->path[6][0] = ft_strdup("ressources/assets/textures/key_red.png");
	gui->len[7] = 1;
	if (!(gui->path[7] = (char**)ft_memalloc(sizeof(char*) * 1)))
		error_exit(2, "error ft_memalloc");
	gui->path[7][0] = ft_strdup("ressources/assets/textures/key_blue.png");
	gui->len[8] = 1;
	if (!(gui->path[8] = (char**)ft_memalloc(sizeof(char*) * 1)))
		error_exit(2, "error ft_memalloc");
	gui->path[8][0] = ft_strdup("ressources/assets/textures/key_green.png");
	gui->len[9] = 1;
	if (!(gui->path[9] = (char**)ft_memalloc(sizeof(char*) * 3)))
		error_exit(2, "error ft_memalloc");
	gui->path[9][0] = ft_strdup("ressources/assets/textures/iron.png");
}

void	load_texture_slope_pack(t_gui *gui)
{
	gui->len[10] = 3;
	if (!(gui->path[10] = (char**)ft_memalloc(sizeof(char*) * 3)))
		error_exit(2, "error ft_memalloc");
	gui->path[10][0] = ft_strdup("ressources/assets/textures/iron.png");
	gui->path[10][1] = ft_strdup("ressources/assets/textures/brick.png");
	gui->path[10][2] = ft_strdup("ressources/assets/textures/wood.png");
	gui->len[11] = 0;
	gui->path[11] = NULL;
	gui->len[12] = 1;
	if (!(gui->path[12] = (char**)ft_memalloc(sizeof(char*) * 1)))
		error_exit(2, "error ft_memalloc");
	gui->path[12][0] = ft_strdup("ressources/assets/textures/health.png");
	gui->len[13] = 1;
	if (!(gui->path[13] = (char**)ft_memalloc(sizeof(char*) * 1)))
		error_exit(2, "error ft_memalloc");
	gui->path[13][0] = ft_strdup("ressources/assets/textures/armor.png");
	gui->len[14] = 1;
	if (!(gui->path[14] = (char**)ft_memalloc(sizeof(char*) * 1)))
		error_exit(2, "error ft_memalloc");
	gui->path[14][0] = ft_strdup("ressources/assets/textures/fuel.png");
}

void	load_texture_ammo_ladder(t_gui *gui)
{
	gui->len[15] = 1;
	if (!(gui->path[15] = (char**)ft_memalloc(sizeof(char*) * 1)))
		error_exit(2, "error ft_memalloc");
	gui->path[15][0] = ft_strdup("ressources/assets/textures/ar.png");
	gui->len[16] = 1;
	if (!(gui->path[16] = (char**)ft_memalloc(sizeof(char*) * 1)))
		error_exit(2, "error ft_memalloc");
	gui->path[16][0] = ft_strdup("ressources/assets/textures/rifle.png");
	gui->len[17] = 1;
	if (!(gui->path[17] = (char**)ft_memalloc(sizeof(char*) * 1)))
		error_exit(2, "error ft_memalloc");
	gui->path[17][0] = ft_strdup("ressources/assets/textures/shotgun.png");
	gui->len[18] = 1;
	if (!(gui->path[18] = (char**)ft_memalloc(sizeof(char*) * 1)))
		error_exit(2, "error ft_memalloc");
	gui->path[18][0] = ft_strdup("ressources/assets/textures/echelle.png");
}

void	load_texture_platform_plane(t_gui *gui)
{
	gui->len[19] = 3;
	if (!(gui->path[19] = (char**)ft_memalloc(sizeof(char*) * 3)))
		error_exit(2, "error ft_memalloc");
	gui->path[19][0] = ft_strdup("ressources/assets/textures/iron.png");
	gui->path[19][1] = ft_strdup("ressources/assets/textures/brick.png");
	gui->path[19][2] = ft_strdup("ressources/assets/textures/wood.png");
	gui->len[20] = 3;
	if (!(gui->path[20] = (char**)ft_memalloc(sizeof(char*) * 3)))
		error_exit(2, "error ft_memalloc");
	gui->path[20][0] = ft_strdup("ressources/assets/textures/metal_f.png");
	gui->path[20][1] = ft_strdup("ressources/assets/textures/grille.png");
	gui->path[20][2] = ft_strdup("ressources/assets/textures/metal_s.png");
}

void	load_texture_end(t_gui *gui)
{
	gui->len[21] = 1;
	if (!(gui->path[21] = (char**)ft_memalloc(sizeof(char*) * 1)))
		error_exit(2, "error ft_memalloc");
	gui->path[21][0] = ft_strdup("ressources/assets/textures/enemy.png");
	gui->len[22] = 1;
	if (!(gui->path[22] = (char**)ft_memalloc(sizeof(char*) * 1)))
		error_exit(2, "error ft_memalloc");
	gui->path[22][0] = ft_strdup("ressources/assets/textures/window.png");
	gui->len[23] = 1;
	if (!(gui->path[23] = (char**)ft_memalloc(sizeof(char*) * 1)))
		error_exit(2, "error ft_memalloc");
	gui->path[23][0] = ft_strdup("ressources/assets/textures/cube_test.png");
	gui->len[24] = 1;
	if (!(gui->path[24] = (char**)ft_memalloc(sizeof(char*) * 1)))
		error_exit(2, "error ft_memalloc");
	gui->path[24][0] = ft_strdup("ressources/assets/textures/cube_test.png");
}
