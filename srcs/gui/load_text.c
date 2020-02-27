/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:24:30 by spuisais          #+#    #+#             */
/*   Updated: 2020/02/14 11:59:00 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	load_letter(t_gui *gui, char *str, int idx)
{
	TTF_Font	*police;
	SDL_Color	color;

	color.r = 0;
	police = TTF_OpenFont("ressources/assets/ttf/Tinos-Regular.ttf", 240);
	gui->letter[idx]->font = TTF_RenderText_Blended(police, str, color);
	gui->letter[idx]->let->surface->w = gui->letter[idx]->font->w;
	gui->letter[idx]->let->surface->h = gui->letter[idx]->font->h;
	gui->letter[idx]->let->surface->intern_format = 4;
	gui->letter[idx]->let->surface->pixels = gui->letter[idx]->font->pixels;
	gui->letter[idx]->let->letter = str[0];
	TTF_CloseFont(police);
}

void	load_menu(t_gui *gui)
{
	gui->menu[0] = png_load("ressources/assets/imgs/Title_screen.png");
	gui->menu[1] = png_load("ressources/assets/imgs/settings_screen.png");
	gui->menu[2] = png_load("ressources/assets/imgs/controls_screen.png");
	gui->menu[3] = png_load("ressources/assets/imgs/credits_screen.png");
	gui->menu[4] = png_load("ressources/assets/imgs/pause_menu.png");
	gui->menu[5] = png_load("ressources/assets/imgs/settings_pause_menu.png");
	gui->menu[6] = png_load("ressources/assets/imgs/Play_menu.png");
	gui->menu[7] = png_load("ressources/assets/imgs/Play_menu.png");
	gui->menu[8] = png_load("ressources/assets/imgs/trainee.png");
	gui->menu[9] = png_load("ressources/assets/imgs/recruit.png");
	gui->menu[10] = png_load("ressources/assets/imgs/pirate.png");
	gui->menu[11] = png_load("ressources/assets/textures/press_key.png");
	gui->menu[12] = png_load("ressources/assets/imgs/Level_editor_menu.png");
	gui->menu[13] = png_load("ressources/assets/imgs/yellow_line.png");
	gui->menu[14] = png_load("ressources/assets/imgs/set_player.png");
	gui->menu[15] = png_load("ressources/assets/imgs/set_weapon.png");
	gui->menu[16] = png_load("ressources/assets/imgs/save_editor.png");
	gui->menu[17] = png_load("ressources/assets/imgs/synopsis.png");
	gui->menu[18] = png_load("ressources/assets/imgs/game_over.png");
	gui->menu[19] = png_load("ressources/assets/imgs/fin_jeu.png");
}

void	load_texture_cube_wall(t_gui *gui)
{
	gui->len[0] = 3;
	if (!(gui->path[0] = (char**)ft_memalloc(sizeof(char*) * 3)))
		error_exit(2, "error ft_memalloc");
	gui->path[0][0] = ft_strdup("ressources/assets/textures/iron.png");
	gui->path[0][1] = ft_strdup("ressources/assets/textures/brick.png");
	gui->path[0][2] = ft_strdup("ressources/assets/textures/wood.png");
	gui->len[1] = 3;
	if (!(gui->path[1] = (char**)ft_memalloc(sizeof(char*) * 3)))
		error_exit(2, "error ft_memalloc");
	gui->path[1][0] = ft_strdup("ressources/assets/textures/iron.png");
	gui->path[1][1] = ft_strdup("ressources/assets/textures/brick.png");
	gui->path[1][2] = ft_strdup("ressources/assets/textures/wood.png");
}

void	load_texture_door(t_gui *gui)
{
	gui->len[2] = 1;
	if (!(gui->path[2] = (char**)ft_memalloc(sizeof(char*) * 1)))
		error_exit(2, "error ft_memalloc");
	gui->path[2][0] = ft_strdup("ressources/assets/textures/door.png");
	gui->len[3] = 1;
	if (!(gui->path[3] = (char**)ft_memalloc(sizeof(char*) * 1)))
		error_exit(2, "error ft_memalloc");
	gui->path[3][0] = ft_strdup("ressources/assets/textures/red_door.png");
	gui->len[4] = 1;
	if (!(gui->path[4] = (char**)ft_memalloc(sizeof(char*) * 1)))
		error_exit(2, "error ft_memalloc");
	gui->path[4][0] = ft_strdup("ressources/assets/textures/blue_door.png");
	gui->len[5] = 1;
	if (!(gui->path[5] = (char**)ft_memalloc(sizeof(char*) * 1)))
		error_exit(2, "error ft_memalloc");
	gui->path[5][0] = ft_strdup("ressources/assets/textures/green_door.png");
}

void	load_path_texture(t_gui *gui)
{
	int	i;
	int	j;

	i = -1;
	load_texture_cube_wall(gui);
	load_texture_door(gui);
	load_texture_key_elevator(gui);
	load_texture_slope_pack(gui);
	load_texture_ammo_ladder(gui);
	load_texture_platform_plane(gui);
	load_texture_end(gui);
	while (++i < 25)
	{
		j = -1;
		while (++j < gui->len[i])
			if (gui->path[i][j] == NULL)
				error_exit(-69, "Error malloc texture");
	}
}
