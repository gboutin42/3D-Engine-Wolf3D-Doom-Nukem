/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 11:05:41 by spuisais          #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		create_face(t_mesh result, char **tab, char **line_split, int k)
{
	t_face		tmp_face;
	int			i;
	int			index[4];
	int			index_uv[4];

	tmp_face = new_face();
	i = -1;
	while (++i < k)
	{
		tab = ft_strsplit(line_split[i + 1], '/');
		index[i] = ft_atoi(tab[0]) - 1;
		if (ft_tablen(tab) >= 2 && ft_strlen(tab[1]) != 0)
			index_uv[i] = ft_atoi(tab[1]) - 1;
		ft_freetab(&tab);
	}
	set_t_face_vertices(&tmp_face, index[0], index[1], index[2]);
	set_t_face_uvs(&tmp_face, index_uv[0], index_uv[1], index_uv[2]);
	t_mesh_add_face(&result, tmp_face);
	if (k == 4)
	{
		set_t_face_vertices(&tmp_face, index[0], index[2], index[3]);
		set_t_face_uvs(&tmp_face, index_uv[0], index_uv[2], index_uv[3]);
		t_mesh_add_face(&result, tmp_face);
	}
}

void		read_obj(t_mesh result, char **line_split, t_vec4 size)
{
	char		**tab;

	tab = NULL;
	if (ft_strcmp(line_split[0], "v") == 0)
	{
		t_mesh_add_point(&result, new_vec4(atof(line_split[1]) * size.x,
		atof(line_split[2]) * size.y, atof(line_split[3]) * size.z));
	}
	else if (ft_strcmp(line_split[0], "vt") == 0)
		t_mesh_add_uv(&result, new_vec4(atof(line_split[1]),
						atof(line_split[2]), 0.0));
	else if (ft_strcmp(line_split[0], "f") == 0)
		create_face(result, tab, line_split, ft_tablen(line_split) - 1);
}

void		do_stuff(char *line, t_mesh result, t_vec4 size)
{
	char		**line_split;

	line_split = NULL;
	line_split = ft_strsplit(line, ' ');
	read_obj(result, line_split, size);
	ft_freetab(&line_split);
}

t_mesh		read_obj_file(char *path, t_vec4 pos, t_vec4 size, char *txtr)
{
	t_mesh		result;
	char		*line;
	int			fd;

	result = new_mesh(pos);
	if ((fd = open(path, O_RDONLY)) < 0)
		error_exit(-8000, "impossible fd");
	line = NULL;
	while (get_next_line(fd, &line))
	{
		if (ft_strlen(line) != 0)
			do_stuff(line, result, size);
		ft_memdel((void**)&line);
	}
	if (txtr != NULL)
		result.texture = png_load(txtr);
	ft_memdel((void**)&line);
	close(fd);
	t_mesh_compute_normals(&result);
	t_mesh_compute_bubble_box(&result);
	result.size = new_vec4(size.x, size.y, size.z);
	return (result);
}
