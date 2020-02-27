/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:59:33 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:59:34 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_LIST_H
# define WOLF3D_LIST_H

# include "wolf3d_mesh.h"
# include "wolf3d_camera.h"

typedef struct	s_mesh_list
{
	t_mesh		*mesh;
	int			size;
	int			max_size;
}				t_mesh_list;

t_mesh_list		new_mesh_list();
t_mesh_list		*initialize_t_mesh_list();
void			t_mesh_list_push_back(t_mesh_list *dest, t_mesh to_add);
void			delete_t_mesh_list(t_mesh_list *dest);
void			free_t_mesh_list(t_mesh_list **dest);
t_mesh			t_mesh_list_at(t_mesh_list *dest, int index);
t_mesh			*t_mesh_list_get(t_mesh_list *dest, int index);

typedef struct	s_camera_list
{
	t_camera	*camera;
	int			size;
	int			max_size;
}				t_camera_list;

t_camera_list	new_camera_list();
t_camera_list	*initialize_t_camera_list();
void			t_camera_list_push_back(t_camera_list *dest, t_camera to_add);
void			t_camera_list_add_back(t_camera_list *dest, t_camera *to_add);
void			delete_t_camera_list(t_camera_list *dest);
void			free_t_camera_list(t_camera_list **dest);
void			clean_t_camera_list(t_camera_list *dest);
t_camera		t_camera_list_at(t_camera_list *dest, int index);
t_camera		*t_camera_list_get(t_camera_list *dest, int index);

#endif
