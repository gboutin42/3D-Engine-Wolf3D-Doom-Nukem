/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_editor2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:47:55 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:47:55 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		print_set_activate_weapon2(t_camera *cam, t_gui *gui, t_player *plr)
{
	if (plr->weapons[3].total_ammo == -1)
		draw_rectangle_texture_cpu(cam->view_port,
			new_rectangle(create_vec2(-0.023, 0.23),
			create_vec2(0.18, 0.1)), gui->menu[13]);
	else
		draw_rectangle_texture_cpu(cam->view_port,
			new_rectangle(create_vec2(-0.151, 0.23),
			create_vec2(0.15, 0.1)), gui->menu[13]);
	if (plr->weapons[4].total_ammo == -1)
		draw_rectangle_texture_cpu(cam->view_port,
			new_rectangle(create_vec2(-0.023, -0.61),
			create_vec2(0.18, 0.1)), gui->menu[13]);
	else
		draw_rectangle_texture_cpu(cam->view_port,
			new_rectangle(create_vec2(-0.151, -0.61),
			create_vec2(0.15, 0.1)), gui->menu[13]);
}

void		print_set_activate_weapon(t_camera *cam, t_gui *gui, t_player *plr)
{
	if (plr->weapons[1].total_ammo == -1)
		draw_rectangle_texture_cpu(cam->view_port,
			new_rectangle(create_vec2(-0.023, 0.65),
			create_vec2(0.18, 0.1)), gui->menu[13]);
	else
		draw_rectangle_texture_cpu(cam->view_port,
			new_rectangle(create_vec2(-0.151, 0.65),
			create_vec2(0.15, 0.1)), gui->menu[13]);
	if (plr->weapons[2].total_ammo == -1)
		draw_rectangle_texture_cpu(cam->view_port,
			new_rectangle(create_vec2(-0.023, -0.19),
			create_vec2(0.18, 0.1)), gui->menu[13]);
	else
		draw_rectangle_texture_cpu(cam->view_port,
			new_rectangle(create_vec2(-0.151, -0.19),
			create_vec2(0.15, 0.1)), gui->menu[13]);
	print_set_activate_weapon2(cam, gui, plr);
}

void		print_set_weapon(t_camera *cam, t_gui *gui, t_engine *engine)
{
	t_player	*plr;

	if (engine->user_engine->player->hitbox.name == NULL)
		return ;
	plr = engine->user_engine->player;
	if (ft_strcmp(plr->hitbox.name, "Player") == 0)
	{
		t_view_port_clear_buffers(cam->view_port);
		print_set_activate_weapon(cam, gui, plr);
		print_set_ar(cam, gui, plr);
		print_set_shotgun(cam, gui, plr);
		print_set_rifle(cam, gui, plr);
		print_set_walldest(cam, gui, plr);
	}
}
