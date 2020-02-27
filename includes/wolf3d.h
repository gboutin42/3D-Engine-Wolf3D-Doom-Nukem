/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:00:41 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 16:00:42 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "wolf3d_includes.h"
# include "wolf3d_define.h"
# include "wolf3d_basic.h"
# include "wolf3d_math.h"
# include "wolf3d_drawing.h"
# include "wolf3d_system.h"
# include "wolf3d_engine.h"
# include "wolf3d_list.h"
# include "wolf3d_algorithm.h"
# include "wolf3d_gui.h"
# include "wolf3d_player.h"
# include "wolf3d_item.h"

typedef void	(*t_playing_funct)(t_camera *, t_gui *, t_engine *, t_mesh);
t_texture		*png_load(char *path);
GLuint			load_shaders(const char *p_vertex_file_path,
						const char *p_fragment_file_path);
t_vec4			convert_screen_to_opengl(t_view_port *p_view_port,
										t_vec4 source);
t_vec4			convert_opengl_to_vec4(t_view_port *p_view_port, t_vec4 source);
float			degree_to_radius(float angle);
float			radius_to_degree(float radian);
t_uv			convert_t_uv_to_texture(t_uv *source);
void			prepare_screen(t_window *win, t_color color);
void			check_frame(t_engine *engine);
void			render_screen(t_engine *engine);
void			clear_buffers(t_window *win);
void			draw_pixel(t_window *p_win, int x, int y, t_color color);
t_triangle		compose_t_triangle_from_t_mesh(t_mesh *src, int *index);
t_triangle		compose_t_triangle_from_t_vertices(t_vec4_list *src,
													int *index);
void			ft_get_leaks(char *prog_name, char *msg);
void			tar_ressources(void);
void			untar_ressources(void);
void			display_title_screen(t_camera *main_camera, t_gui *gui,
									t_engine *engine, t_mesh mesh);
void			game_playing(t_camera *main_camera, t_gui *gui,
									t_engine *engine, t_mesh mesh);
void			game_paused(t_camera *main_camera, t_gui *gui,
									t_engine *engine, t_mesh mesh);
void			level_editing(t_camera *main_camera, t_gui *gui,
									t_engine *engine, t_mesh mesh);
void			level_editing_paused(t_camera *main_camera, t_gui *gui,
									t_engine *engine, t_mesh mesh);

#endif
