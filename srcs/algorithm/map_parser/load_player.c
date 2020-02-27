/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:40:33 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_mesh			init_mesh(char **line_split)
{
	t_mesh		mesh;
	t_vec4		vector[3];

	vector[0] = new_vec4(ft_atof(line_split[2]),
								ft_atof(line_split[3]) + 0.2,
								ft_atof(line_split[4]));
	vector[1] = new_vec4(ft_atof(line_split[5]),
								ft_atof(line_split[6]),
								ft_atof(line_split[7]));
	vector[2] = new_vec4(ft_atof(line_split[10]),
								ft_atof(line_split[11]),
								ft_atof(line_split[12]));
	mesh = create_cube(vector[0], vector[1], NULL,
		ft_atof(line_split[9]));
	t_mesh_rotate(&mesh, vector[2]);
	mesh.hp = ft_atoi(line_split[17]);
	mesh.no_hitbox = 0;
	mesh.primitive = -1;
	mesh.kinetic = ft_atof(line_split[9]);
	t_mesh_set_name(&mesh, line_split[1]);
	return (mesh);
}

void			init_player(t_player *player, char **line_split)
{
	player->hp = ft_atoi(line_split[17]);
	player->armor = ft_atoi(line_split[18]);
	player->fuel = ft_atoi(line_split[19]);
	player->weapons[0] = new_weapons(0,
			ft_atoi(line_split[20]), ft_atoi(line_split[21]));
	player->weapons[1] = new_weapons(1,
			ft_atoi(line_split[22]), ft_atoi(line_split[23]));
	player->weapons[2] = new_weapons(2,
			ft_atoi(line_split[24]), ft_atoi(line_split[25]));
	player->weapons[3] = new_weapons(3,
			ft_atoi(line_split[26]), ft_atoi(line_split[27]));
	player->weapons[4] = new_weapons(4,
			ft_atoi(line_split[28]), ft_atoi(line_split[29]));
	player->weapons[5] = new_weapons(5, 0, 0);
	player->red_card = ft_atoi(line_split[30]);
	player->blue_card = ft_atoi(line_split[31]);
	player->green_card = ft_atoi(line_split[32]);
	player->current_weapon = &player->weapons[0];
}

void			read_player(char **line_split, t_player *player)
{
	if (ft_strcmp(line_split[0], "player:") == 0)
	{
		player->hitbox = init_mesh(line_split);
		t_mesh_set_color(&player->hitbox, new_color(0.5, 0.6, 0.0, 1.0));
		init_player(player, line_split);
	}
}
