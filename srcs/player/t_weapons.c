/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_weapons.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 09:37:24 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:00 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			new_weapons3(int ammo, int total_ammo, t_weapon *result)
{
	result[4].name = "rpg";
	result[4].ammo = ammo;
	result[4].mag_size = 1;
	result[4].max_ammo = result[4].mag_size * MAX_MAGS;
	result[4].total_ammo = total_ammo;
	result[4].dmg = 200000;
	result[4].tick_shoot = 1;
	result[4].tick_reload = 4;
	result[4].index = 4;
	result[5].name = "bb";
	result[5].ammo = 2;
	result[5].total_ammo = 1;
	result[5].dmg = 0;
	result[5].index = 5;
}

void			new_weapons2(int ammo, int total_ammo, t_weapon *result)
{
	result[2].name = "rifle";
	result[2].ammo = ammo;
	result[2].mag_size = 10;
	result[2].max_ammo = result[2].mag_size * MAX_MAGS;
	result[2].total_ammo = total_ammo;
	result[2].dmg = 50;
	result[2].tick_shoot = 2;
	result[2].tick_reload = 3;
	result[2].index = 2;
	result[3].name = "shotgun";
	result[3].ammo = ammo;
	result[3].mag_size = 8;
	result[3].max_ammo = result[3].mag_size * MAX_MAGS;
	result[3].total_ammo = total_ammo;
	result[3].dmg = 120;
	result[3].tick_shoot = 2;
	result[3].tick_reload = 3;
	result[3].index = 3;
	new_weapons3(ammo, total_ammo, result);
}

t_weapon		new_weapons(int index, int ammo, int total_ammo)
{
	t_weapon	result[6];

	result[0].name = "pistol";
	result[0].ammo = ammo;
	result[0].mag_size = 15;
	result[0].max_ammo = result[0].mag_size * MAX_MAGS;
	result[0].total_ammo = total_ammo;
	result[0].dmg = 10;
	result[0].tick_shoot = 4;
	result[0].tick_reload = 2;
	result[0].index = 0;
	result[1].name = "ar";
	result[1].ammo = ammo;
	result[1].mag_size = 30;
	result[1].max_ammo = result[1].mag_size * MAX_MAGS;
	result[1].total_ammo = total_ammo;
	result[1].dmg = 25;
	result[1].tick_shoot = 1;
	result[1].tick_reload = 2;
	result[1].index = 1;
	new_weapons2(ammo, total_ammo, result);
	return (result[index]);
}
