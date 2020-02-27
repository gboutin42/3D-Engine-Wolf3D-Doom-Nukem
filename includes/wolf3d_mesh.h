/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_mesh.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:00:01 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 16:00:02 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_MESH_H
# define WOLF3D_MESH_H

# include "wolf3d_basic_list.h"
# include "wolf3d_window.h"

typedef struct			s_door
{
	int					tick;
	int					state;
	int					move;
}						t_door;

t_door					new_door(void);
t_door					*initialize_t_door(void);

typedef struct			s_mesh
{
	struct s_camera		*camera;
	t_vec4				pos;
	t_vec4				size;
	t_vec4				center;
	int					is_visible;
	float				bubble_radius;
	int					collectible;

	t_vec4				rotation;
	t_vec4				angle;
	t_vec4				forward;
	t_vec4				right;
	t_vec4				up;

	t_vec4				force;
	float				kinetic;

	t_texture			*texture;

	t_vec4_list			*vertices_in_world;
	t_vec4_list			*next_vert;

	t_vec4_list			*vertices;
	t_vec4_list			*uvs;
	t_vec4_list			*normales;
	t_face_list			*faces;

	char				*name;
	t_door				door;

	int					no_hitbox;
	int					primitive;
	int					hp;
	int					tick;
}						t_mesh;

t_mesh					new_mesh(t_vec4 pos);
t_mesh					read_obj_file(char *path, t_vec4 pos, t_vec4 size,
										char *txtr);
void					delete_t_mesh(t_mesh *mesh);
void					free_t_mesh(t_mesh **mesh);
void					t_mesh_add_point(t_mesh *dest, t_vec4 new_point);
void					t_mesh_add_uv(t_mesh *dest, t_vec4 new_uv);
void					t_mesh_add_face(t_mesh *dest, t_face new_face);
void					t_mesh_set_texture(t_mesh *dest, t_texture *p_texture);
void					t_mesh_set_color(t_mesh *dest, t_color p_color);
void					t_mesh_compute_normals(t_mesh *mesh);
void					t_mesh_compute_bubble_box(t_mesh *mesh);
void					t_mesh_move(t_mesh *dest, t_vec4 delta);
void					activate_gravity(t_mesh *dest, float gravity);
void					t_mesh_apply_force(t_mesh *dest);
t_mesh					create_cube(t_vec4 coord, t_vec4 size,
							char *texture_path, float gravity);
t_mesh					create_plane(t_vec4 pos, t_vec4 size,
							char *texture_path, float gravity);
t_mesh					create_vertical_plane(t_vec4 pos,
							t_vec4 size, char *texture_path, float gravity);
t_mesh					create_skybox(t_vec4 pos, t_vec4 size,
							t_texture *p_texture);
t_mesh					create_cave(t_vec4 pos, t_vec4 size,
							char *texture_path, float gravity);
void					t_mesh_rotate(t_mesh *mesh, t_vec4 delta_angle);
void					t_mesh_rotate_to(t_mesh *src, t_mesh *dest);
void					t_mesh_rotate_around_point(t_mesh *mesh,
							t_vec4 delta_angle, t_vec4 center);
void					t_mesh_look_at(t_mesh *mesh);
void					t_mesh_set_visibility(t_mesh *dest, int new_state);
void					t_mesh_compute_vertices_in_world(t_mesh *dest);
void					t_mesh_comp_next_vert_world(t_mesh *dest,
							t_vec4 axis);
void					t_mesh_resize(t_mesh *mesh, t_vec4 modif);
void					t_mesh_set_name(t_mesh *mesh, char *name);
int						t_mesh_on_mesh(t_mesh *body, t_mesh *target);
void					destroy_mesh(t_mesh *mesh);
t_mesh					create_mesh_cube_wall(int index);
t_mesh					create_mesh_door(int index, t_mesh mesh);
t_mesh					create_mesh_card(int index, t_mesh mesh);
t_mesh					create_mesh_elevator(int index, t_mesh mesh);
t_mesh					create_mesh_slope(int index, t_mesh mesh);
t_mesh					create_mesh_item(int index, t_mesh mesh);
t_mesh					create_mesh_ammo(int index, t_mesh mesh);
t_mesh					create_mesh_ladder_platform(int index, t_mesh mesh);
t_mesh					create_mesh_plane_enemy(int index, t_mesh mesh);
t_mesh					create_mesh_window_player(int index, t_mesh mesh);
t_mesh					create_mesh_end(int index, t_mesh mesh);

typedef struct			s_mesh_editing
{
	t_mesh				mesh;
	char				*path;
}						t_mesh_editing;

#endif
