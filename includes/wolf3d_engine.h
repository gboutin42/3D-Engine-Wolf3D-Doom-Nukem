/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_engine.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:58:36 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:58:36 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_ENGINE_H
# define WOLF3D_ENGINE_H

# include "wolf3d_camera.h"
# include "wolf3d_engine_module.h"
# include "wolf3d_item.h"

typedef struct		s_engine
{
	t_window		*win;
	int				playing;
	int				menu_nbr;
	int				display_skybox;
	int				tick;
	float			difficulty;
	t_camera		*main_camera;
	t_visual_engine	*visual_engine;
	t_physic_engine	*physic_engine;
	t_user_engine	*user_engine;
	t_sound_engine	*sound_engine;
}					t_engine;

void				free_t_window(t_window **dest);
t_engine			new_engine(t_window *p_window);
t_engine			*initialize_t_engine(t_window *p_window);
void				delete_t_engine(t_engine *dest);
void				free_t_engine(t_engine **dest);
void				t_engine_add_mesh(t_engine *engine, t_mesh p_mesh);
void				t_engine_add_item(t_engine *engine, t_item p_item);
t_mesh				*t_engine_get_mesh(t_engine *p_engine, int index);
void				t_engine_handle_camera(t_engine *p_engine, t_window *p_win);
void				t_engine_draw_mesh(t_engine *p_engine);
void				t_engine_apply_physic(t_engine *engine);
void				t_engine_place_camera(t_engine *engine, int index,
														t_vec4 p_new_pos);
void				t_engine_camera_look_at(t_engine *engine, int index,
														t_vec4 target);
void				t_engine_render_camera(t_engine *engine);
void				t_engine_prepare_camera(t_engine *engine);
void				t_engine_add_camera(t_engine *p_engine,
														t_camera new_camera);
int					can_move(t_mesh *mesh, t_engine *engine);
void				handle_camera_mouvement_by_key(t_camera *camera,
									t_keyboard *p_keyboard, t_engine *engine);
void				move_camera(t_camera *camera, t_engine *engine, float j);
void				move_cam(t_camera *camera, t_keyboard *key);
void				t_user_engine_handle_camera(t_engine *engine,
											t_camera *cam, t_window *p_win);
void				t_physic_engine_apply_force(t_engine *engine);
void				player_action(t_camera *camera, t_keyboard *p_keyboard,
								t_engine *engine, t_texture **texture_weapons);
void				shoot_weapon(t_engine *engine, t_camera *camera,
								t_texture **texture_weapons);
void				player_take_dmg(t_engine *engine, int dmg);
void				enemy_shoot(t_engine *engine);
void				enemy_look(t_engine *engine);
void				enemy_move(t_engine *engine);
void				enemy_boss_look(t_engine *engine);
void				enemy_boss_shoot(t_engine *engine);
void				enemy_boss_spawn(t_engine *engine);
void				save_map(t_engine *engine, int which);
void				save_player(t_engine *engine, int fd);
void				link_camera_to_mesh(t_engine *engine, int index,
																t_mesh *mesh);
t_mesh_editing		create_mesh_editing(int index, char *path);
void				cast_mesh(t_engine *engine, t_mesh *mesh_editing);
void				load_map(t_camera *main_camera, t_engine *engine,
																char *path);
void				t_mesh_move_door(t_mesh	*mesh, t_engine *engine);
void				player_take_dmg(t_engine *engine, int dmg);
void				check_mesh_player(t_engine *engine, t_mesh mesh);
void				place_mesh(t_engine *engine, t_mesh_editing edit);
void				rotate_mesh(t_engine *engine);
void				left_move(t_engine *engine);
void				right_move(t_engine *engine);
void				up_move(t_engine *engine);
void				down_move(t_engine *engine);
void				equals_move(t_engine *engine);
void				minus_move(t_engine *engine);
void				jump(t_keyboard *keyboard, t_player *player, t_camera *cam,
															t_engine *engine);
float				control_up_down_next(t_camera *cam, t_mesh_list *meshs);
float				control_up_down(t_keyboard *keyboard, t_camera *cam,
															t_engine *engine);
t_vec4				forward_backward(t_keyboard *keyboard, t_camera *cam,
													t_vec4 tmp, t_vec4 save);
t_vec4				left_right(t_keyboard *keyboard, t_camera *cam, t_vec4 tmp,
																t_vec4 save);
int					t_engine_return_mesh_len(t_engine *engine);
void				reload_weapon(t_camera *camera, t_player *player, int tick,
															t_engine *engine);
void				t_p_engine_comp_vert_world(t_physic_engine *physic_engine);

#endif
