/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mesh.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 10:04:38 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_mesh	new_mesh(t_vec4 pos)
{
	t_mesh		result;

	result.camera = NULL;
	result.primitive = 10;
	result.pos = pos;
	result.is_visible = BOOL_TRUE;
	result.center = pos;
	result.bubble_radius = 0.0;
	result.collectible = 0;
	result.force = new_vec4(0.0, 0.0, 0.0);
	result.kinetic = 0.0;
	result.angle = new_vec4(0.0, 90.0, 0.0);
	result.texture = NULL;
	result.name = NULL;
	result.no_hitbox = 0;
	result.hp = 0;
	result.vertices_in_world = initialize_t_vec4_list();
	result.next_vert = initialize_t_vec4_list();
	result.vertices = initialize_t_vec4_list();
	result.uvs = initialize_t_vec4_list();
	result.faces = initialize_t_face_list();
	result.normales = initialize_t_vec4_list();
	result.rotation = new_vec4(0.0, 0.0, 0.0);
	t_mesh_look_at(&result);
	return (result);
}

void	delete_t_mesh(t_mesh *mesh)
{
	int i;

	i = -1;
	ft_strdel(&mesh->name);
	if (mesh->vertices_in_world != NULL)
		free_t_vec4_list(&mesh->vertices_in_world);
	if (mesh->next_vert != NULL)
		free_t_vec4_list(&mesh->next_vert);
	if (mesh->vertices != NULL)
		free_t_vec4_list(&mesh->vertices);
	if (mesh->normales != NULL)
		free_t_vec4_list(&mesh->normales);
	if (mesh->uvs != NULL)
		free_t_vec4_list(&(mesh)->uvs);
	if (mesh->texture != NULL)
		free_t_texture(&mesh->texture);
	ft_memdel((void**)&mesh->faces->face);
	ft_memdel((void**)&mesh->faces);
}

void	free_t_mesh(t_mesh **mesh)
{
	delete_t_mesh(*mesh);
}

void	t_mesh_resize(t_mesh *mesh, t_vec4 modif)
{
	t_vec4		tmp;
	int			i;

	i = 4;
	while (i <= 7)
	{
		tmp = t_vec4_list_at(mesh->vertices, i);
		tmp = add_vec4(tmp, modif);
		t_vec4_list_set(mesh->vertices, i, &tmp);
		i++;
	}
}

void	destroy_mesh(t_mesh *mesh)
{
	mesh->no_hitbox = 1;
	t_mesh_set_visibility(mesh, BOOL_FALSE);
	ft_strdel(&mesh->name);
	t_mesh_set_name(mesh, "mesh_destroy");
}
