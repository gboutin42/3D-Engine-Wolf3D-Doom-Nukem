/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:52:12 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/21 16:39:10 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			exit_prog(t_engine **engine, t_gui **gui,
														t_playing_funct **play)
{
	free_t_gui(*gui);
	ft_memdel((void**)play);
	free_t_engine(engine);
	Mix_CloseAudio();
	Mix_Quit();
	TTF_Quit();
	SDL_Quit();
}

void			begin_prog(t_engine **engine, t_gui **gui, char **argv)
{
	t_window	*win;

	untar_ressources();
	start_sdl();
	TTF_Init();
	Mix_Init(MIX_INIT_OGG);
	if (Mix_OpenAudio(44100, AUDIO_S16SYS, 1, 1024) == -1)
		error_exit(-100, (char*)Mix_GetError());
	win = initialize_t_window(argv[0], WIN_X, WIN_Y);
	*engine = initialize_t_engine(win);
	*gui = initialize_t_gui();
	load_menu(*gui);
	set_t_gui_texte(*gui);
	create_minimap(*engine);
}

void			load_textures(t_gui *gui)
{
	gui->text_am[0] = png_load("ressources/assets/textures/pistol_ammo.png");
	gui->text_am[1] = png_load("ressources/assets/textures/ar_ammo.png");
	gui->text_am[2] = png_load("ressources/assets/textures/rifle_ammo.png");
	gui->text_am[3] = png_load("ressources/assets/textures/shotgun_ammo.png");
	gui->text_am[4] = png_load(
						"ressources/assets/textures/wall_destroyer_ammo.png");
	gui->text_am[5] = png_load("ressources/assets/imgs/Hands_baby.png");
	gui->text_weap[0] = png_load("ressources/assets/imgs/pistol.png");
	gui->text_weap[1] = png_load("ressources/assets/imgs/ar.png");
	gui->text_weap[2] = png_load("ressources/assets/imgs/rifle.png");
	gui->text_weap[3] = png_load("ressources/assets/imgs/shotgun.png");
	gui->text_weap[4] = png_load("ressources/assets/imgs/wall_destroyer.png");
	gui->text_weap[5] = png_load("ressources/assets/imgs/Hands_baby.png");
	gui->text_weap[6] = png_load("ressources/assets/imgs/pistol_shoot_0.png");
	gui->text_weap[7] = png_load("ressources/assets/imgs/ar_shoot_0.png");
	gui->text_weap[8] = png_load("ressources/assets/imgs/rifle_shoot_0.png");
	gui->text_weap[9] = png_load("ressources/assets/imgs/shotgun_shoot_0.png");
	gui->text_weap[10] = png_load(
						"ressources/assets/imgs/wall_destroyer_shoot_0.png");
	gui->skybox = png_load("ressources/assets/textures/skybox1.png");
}

t_playing_funct	*initialize_prog(t_gui **gui, t_engine **engine, char **argv)
{
	t_playing_funct	*result;

	begin_prog(engine, gui, argv);
	load_path_texture(*gui);
	load_textures(*gui);
	Mix_VolumeMusic(MIX_MAX_VOLUME);
	Mix_PlayMusic((*engine)->sound_engine->music[0], -1);
	if (!(result = (t_playing_funct *)ft_memalloc(sizeof(t_playing_funct) * 6)))
		error_exit(-56, "t_playing_funct can't be ft_memalloc");
	result[0] = NULL;
	result[1] = display_title_screen;
	result[2] = game_playing;
	result[3] = game_paused;
	result[4] = level_editing;
	result[5] = level_editing_paused;
	return (result);
}

int				main(int argc, char **argv)
{
	t_engine		*engine;
	t_gui			*gui;
	t_playing_funct	*playing_functions;
	t_camera		*camera;
	t_mesh			mesh;

	if (argc != 1)
		error_exit(-1, "Bad argument");
	engine = NULL;
	gui = NULL;
	playing_functions = initialize_prog(&gui, &engine, argv);
	camera = t_camera_list_get(engine->visual_engine->camera_list, 0);
	mesh = create_skybox(camera->pos, new_vec4(1.0, 1.0, 1.0),
						gui->skybox);
	while (engine->playing != 0)
	{
		prepare_screen(engine->win, new_color(0.2f, 0.2f, 0.2f, 1.0f));
		t_engine_prepare_camera(engine);
		if (engine->playing != 0)
			playing_functions[engine->playing](camera, gui, engine, mesh);
		t_engine_handle_event(camera, gui, engine);
		render_screen(engine);
	}
	exit_prog(&engine, &gui, &playing_functions);
	return (0);
}
