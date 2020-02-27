/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_set_weapon.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:48:00 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:48:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		print_set_ar(t_camera *cam, t_gui *gui, t_player *plr)
{
	if (plr->weapons[1].total_ammo == 0 && plr->weapons[1].ammo == 0)
		draw_rectangle_texture_cpu(cam->view_port,
			new_rectangle(create_vec2(0.04, 0.52),
			create_vec2(0.08, 0.1)), gui->menu[13]);
	if (plr->weapons[1].total_ammo == 0 && plr->weapons[1].ammo == 30)
		draw_rectangle_texture_cpu(cam->view_port,
			new_rectangle(create_vec2(0.1, 0.52),
			create_vec2(0.08, 0.1)), gui->menu[13]);
	if (plr->weapons[1].total_ammo == 30 && plr->weapons[1].ammo == 30)
		draw_rectangle_texture_cpu(cam->view_port,
			new_rectangle(create_vec2(0.16, 0.52),
			create_vec2(0.08, 0.1)), gui->menu[13]);
	if (plr->weapons[1].total_ammo == 60 && plr->weapons[1].ammo == 30)
		draw_rectangle_texture_cpu(cam->view_port,
			new_rectangle(create_vec2(0.22, 0.52),
			create_vec2(0.08, 0.1)), gui->menu[13]);
	if (plr->weapons[1].total_ammo == 90 && plr->weapons[1].ammo == 30)
		draw_rectangle_texture_cpu(cam->view_port,
			new_rectangle(create_vec2(0.285, 0.52),
			create_vec2(0.08, 0.1)), gui->menu[13]);
	if (plr->weapons[1].total_ammo == 120 && plr->weapons[1].ammo == 30)
		draw_rectangle_texture_cpu(cam->view_port,
			new_rectangle(create_vec2(0.348, 0.52),
			create_vec2(0.08, 0.1)), gui->menu[13]);
}

void		print_set_rifle(t_camera *cam, t_gui *gui, t_player *plr)
{
	if (plr->weapons[2].total_ammo == 0 && plr->weapons[2].ammo == 0)
		draw_rectangle_texture_cpu(cam->view_port,
			new_rectangle(create_vec2(0.042, -0.33),
			create_vec2(0.08, 0.1)), gui->menu[13]);
	if (plr->weapons[2].total_ammo == 0 && plr->weapons[2].ammo == 10)
		draw_rectangle_texture_cpu(cam->view_port,
			new_rectangle(create_vec2(0.105, -0.33),
			create_vec2(0.08, 0.1)), gui->menu[13]);
	if (plr->weapons[2].total_ammo == 10 && plr->weapons[2].ammo == 10)
		draw_rectangle_texture_cpu(cam->view_port,
			new_rectangle(create_vec2(0.162, -0.33),
			create_vec2(0.08, 0.1)), gui->menu[13]);
	if (plr->weapons[2].total_ammo == 20 && plr->weapons[2].ammo == 10)
		draw_rectangle_texture_cpu(cam->view_port,
			new_rectangle(create_vec2(0.222, -0.33),
			create_vec2(0.08, 0.1)), gui->menu[13]);
	if (plr->weapons[2].total_ammo == 30 && plr->weapons[2].ammo == 10)
		draw_rectangle_texture_cpu(cam->view_port,
			new_rectangle(create_vec2(0.287, -0.33),
			create_vec2(0.08, 0.1)), gui->menu[13]);
	if (plr->weapons[2].total_ammo == 40 && plr->weapons[2].ammo == 10)
		draw_rectangle_texture_cpu(cam->view_port,
			new_rectangle(create_vec2(0.35, -0.33),
			create_vec2(0.08, 0.1)), gui->menu[13]);
}

void		print_set_shotgun(t_camera *cam, t_gui *gui, t_player *plr)
{
	if (plr->weapons[3].total_ammo == 0 && plr->weapons[3].ammo == 0)
		draw_rectangle_texture_cpu(cam->view_port,
			new_rectangle(create_vec2(0.035, 0.095),
			create_vec2(0.08, 0.1)), gui->menu[13]);
	if (plr->weapons[3].total_ammo == 0 && plr->weapons[3].ammo == 8)
		draw_rectangle_texture_cpu(cam->view_port,
			new_rectangle(create_vec2(0.095, 0.095),
			create_vec2(0.08, 0.1)), gui->menu[13]);
	if (plr->weapons[3].total_ammo == 8 && plr->weapons[3].ammo == 8)
		draw_rectangle_texture_cpu(cam->view_port,
			new_rectangle(create_vec2(0.155, 0.095),
			create_vec2(0.08, 0.1)), gui->menu[13]);
	if (plr->weapons[3].total_ammo == 16 && plr->weapons[3].ammo == 8)
		draw_rectangle_texture_cpu(cam->view_port,
			new_rectangle(create_vec2(0.215, 0.095),
			create_vec2(0.08, 0.1)), gui->menu[13]);
	if (plr->weapons[3].total_ammo == 24 && plr->weapons[3].ammo == 8)
		draw_rectangle_texture_cpu(cam->view_port,
			new_rectangle(create_vec2(0.28, 0.095),
			create_vec2(0.08, 0.1)), gui->menu[13]);
	if (plr->weapons[3].total_ammo == 32 && plr->weapons[3].ammo == 8)
		draw_rectangle_texture_cpu(cam->view_port,
			new_rectangle(create_vec2(0.343, 0.095),
			create_vec2(0.08, 0.1)), gui->menu[13]);
}

void		print_set_walldest(t_camera *cam, t_gui *gui, t_player *plr)
{
	if (plr->weapons[4].total_ammo == 0 && plr->weapons[4].ammo == 0)
		draw_rectangle_texture_cpu(cam->view_port,
			new_rectangle(create_vec2(0.042, -0.755),
			create_vec2(0.08, 0.1)), gui->menu[13]);
	if (plr->weapons[4].total_ammo == 0 && plr->weapons[4].ammo == 1)
		draw_rectangle_texture_cpu(cam->view_port,
			new_rectangle(create_vec2(0.105, -0.755),
			create_vec2(0.08, 0.1)), gui->menu[13]);
	if (plr->weapons[4].total_ammo == 1 && plr->weapons[4].ammo == 1)
		draw_rectangle_texture_cpu(cam->view_port,
			new_rectangle(create_vec2(0.162, -0.755),
			create_vec2(0.08, 0.1)), gui->menu[13]);
	if (plr->weapons[4].total_ammo == 2 && plr->weapons[4].ammo == 1)
		draw_rectangle_texture_cpu(cam->view_port,
			new_rectangle(create_vec2(0.222, -0.755),
			create_vec2(0.08, 0.1)), gui->menu[13]);
	if (plr->weapons[4].total_ammo == 3 && plr->weapons[4].ammo == 1)
		draw_rectangle_texture_cpu(cam->view_port,
			new_rectangle(create_vec2(0.287, -0.755),
			create_vec2(0.08, 0.1)), gui->menu[13]);
	if (plr->weapons[4].total_ammo == 4 && plr->weapons[4].ammo == 1)
		draw_rectangle_texture_cpu(cam->view_port,
			new_rectangle(create_vec2(0.35, -0.755),
			create_vec2(0.08, 0.1)), gui->menu[13]);
}
