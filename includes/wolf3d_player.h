/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_player.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:59:07 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:59:08 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_PLAYER_H
# define WOLF3D_PLAYER_H
# define MAX_MAGS 5

# include "wolf3d_camera.h"

typedef struct	s_weapon
{
	char		*name;
	int			ammo;
	int			mag_size;
	int			total_ammo;
	int			max_ammo;
	int			dmg;
	int			tick_shoot;
	int			tick_reload;
	int			index;
}				t_weapon;

typedef struct	s_player
{
	t_camera	*camera;
	t_mesh		hitbox;
	int			hp;
	int			armor;
	int			fuel;
	float		speed;
	t_weapon	weapons[6];
	t_weapon	*current_weapon;
	int			red_card;
	int			blue_card;
	int			green_card;
	int			shoot_time;
	int			reload_time;
	float		difficulty;
}				t_player;

t_player		new_player(t_camera *cam);
t_player		*initialize_t_player(t_camera *cam);
void			read_player(char **split, t_player *player);
t_weapon		new_weapons(int index, int ammo, int total_ammo);
t_mesh_list		*read_map_file(int fd, t_player *player);
void			change_weapon(t_keyboard *p_keyboard, t_player *player);

#endif
