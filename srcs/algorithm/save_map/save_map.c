/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:46:27 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	save_color(t_mesh cu, int fd, char **str)
{
	*str = ft_strjoinf(*str, ft_ftoa(cu.rotation.x), 3);
	*str = ft_strjoinf(*str, " ", 1);
	*str = ft_strjoinf(*str, ft_ftoa(cu.rotation.y), 3);
	*str = ft_strjoinf(*str, " ", 1);
	*str = ft_strjoinf(*str, ft_ftoa(cu.rotation.z), 3);
	*str = ft_strjoinf(*str, " ", 1);
	*str = ft_strjoinf(*str, ft_ftoa(t_face_list_get(cu.faces, 0)->color.r), 3);
	*str = ft_strjoinf(*str, " ", 1);
	*str = ft_strjoinf(*str, ft_ftoa(t_face_list_get(cu.faces, 0)->color.g), 3);
	*str = ft_strjoinf(*str, " ", 1);
	*str = ft_strjoinf(*str, ft_ftoa(t_face_list_get(cu.faces, 0)->color.b), 3);
	*str = ft_strjoinf(*str, " ", 1);
	*str = ft_strjoinf(*str, ft_ftoa(t_face_list_get(cu.faces, 0)->color.a), 3);
	*str = ft_strjoinf(*str, " ", 1);
	*str = ft_strjoinf(*str, ft_itoa(cu.hp), 3);
	*str = ft_strjoinf(*str, " ", 1);
	if (cu.no_hitbox == 1)
		*str = ft_strjoinf(*str, "#\n", 1);
	else if (cu.is_visible == 0)
		*str = ft_strjoinf(*str, "*\n", 1);
	else
		*str = ft_strjoinf(*str, "\n", 1);
	write(fd, *str, ft_strlen(*str));
}

void	save_pos(t_mesh current, int fd, char **str)
{
	*str = ft_strjoinf(*str, ft_ftoa(current.pos.x), 3);
	*str = ft_strjoinf(*str, " ", 1);
	*str = ft_strjoinf(*str, ft_ftoa(current.pos.y), 3);
	*str = ft_strjoinf(*str, " ", 1);
	*str = ft_strjoinf(*str, ft_ftoa(current.pos.z), 3);
	*str = ft_strjoinf(*str, " ", 1);
	*str = ft_strjoinf(*str, ft_ftoa(current.size.x), 3);
	*str = ft_strjoinf(*str, " ", 1);
	*str = ft_strjoinf(*str, ft_ftoa(current.size.y), 3);
	*str = ft_strjoinf(*str, " ", 1);
	*str = ft_strjoinf(*str, ft_ftoa(current.size.z), 3);
	*str = ft_strjoinf(*str, " ", 1);
	if (current.texture != NULL)
	{
		*str = ft_strjoinf(*str, current.texture->path, 1);
		*str = ft_strjoinf(*str, " ", 1);
	}
	else
		*str = ft_strjoinf(*str, "NULL ", 1);
	*str = ft_strjoinf(*str, ft_ftoa(current.kinetic), 3);
	*str = ft_strjoinf(*str, " ", 1);
	save_color(current, fd, str);
}

void	save_name(t_mesh current, int fd)
{
	char	*str;

	str = NULL;
	if (ft_strcmp(current.name, "end") == 0)
	{
		str = ft_strdup("plane: ");
		current.size.y = 0.0;
	}
	else if (current.collectible == 1)
		str = ft_strdup("item: ");
	else if (current.primitive == 0)
		str = ft_strdup("plane: ");
	else if (current.primitive == 1)
		str = ft_strdup("cube: ");
	else if (current.primitive == 10)
	{
		str = ft_strdup("#");
		str = ft_strjoinf(str, current.name, 1);
		str = ft_strjoinf(str, " ", 1);
	}
	str = ft_strjoinf(str, current.name, 1);
	str = ft_strjoinf(str, " ", 1);
	save_pos(current, fd, &str);
	ft_strdel(&str);
}

char	*command_system(int which)
{
	char	*file;
	char	*command;

	file = ft_itoa(which);
	command = ft_strjoin("ressources/map/save", file);
	command = ft_strjoinf(command, ".map", 1);
	remove((const char*)command);
	ft_strdel(&command);
	command = ft_strjoinf("touch ressources/map/save", file, 2);
	command = ft_strjoinf(command, ".map", 1);
	system(command);
	return (command);
}

void	save_map(t_engine *engine, int which)
{
	char	*command;
	int		i;
	int		fd;
	t_mesh	current;

	command = command_system(which);
	fd = open(command + 6, O_WRONLY);
	ft_strdel(&command);
	if (fd < 0)
		error_exit(-7001, "impossible fd");
	save_player(engine, fd);
	i = 0;
	while (i < engine->physic_engine->mesh_list->size)
	{
		current = t_mesh_list_at(engine->physic_engine->mesh_list, i);
		if (current.primitive >= 0 && (current.is_visible
			|| !current.no_hitbox) && ft_strcmp(current.name, "Player") != 0)
			save_name(current, fd);
		i++;
	}
	close(fd);
}
