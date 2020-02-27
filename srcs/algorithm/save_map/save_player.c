/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:39:37 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	save_card(t_player *player, int fd, char **str)
{
	*str = ft_strjoinf(*str, ft_itoa(player->red_card), 3);
	*str = ft_strjoinf(*str, " ", 1);
	*str = ft_strjoinf(*str, ft_itoa(player->blue_card), 3);
	*str = ft_strjoinf(*str, " ", 1);
	*str = ft_strjoinf(*str, ft_itoa(player->green_card), 3);
	write(fd, *str, ft_strlen(*str));
	write(fd, "\n", 1);
}

void	save_ammo(t_player *player, int fd, char **str)
{
	*str = ft_strjoinf(*str, ft_itoa(player->weapons[0].ammo), 3);
	*str = ft_strjoinf(*str, " ", 1);
	*str = ft_strjoinf(*str, ft_itoa(player->weapons[0].total_ammo), 3);
	*str = ft_strjoinf(*str, " ", 1);
	*str = ft_strjoinf(*str, ft_itoa(player->weapons[1].ammo), 3);
	*str = ft_strjoinf(*str, " ", 1);
	*str = ft_strjoinf(*str, ft_itoa(player->weapons[1].total_ammo), 3);
	*str = ft_strjoinf(*str, " ", 1);
	*str = ft_strjoinf(*str, ft_itoa(player->weapons[2].ammo), 3);
	*str = ft_strjoinf(*str, " ", 1);
	*str = ft_strjoinf(*str, ft_itoa(player->weapons[2].total_ammo), 3);
	*str = ft_strjoinf(*str, " ", 1);
	*str = ft_strjoinf(*str, ft_itoa(player->weapons[3].ammo), 3);
	*str = ft_strjoinf(*str, " ", 1);
	*str = ft_strjoinf(*str, ft_itoa(player->weapons[3].total_ammo), 3);
	*str = ft_strjoinf(*str, " ", 1);
	*str = ft_strjoinf(*str, ft_itoa(player->weapons[4].ammo), 3);
	*str = ft_strjoinf(*str, " ", 1);
	*str = ft_strjoinf(*str, ft_itoa(player->weapons[4].total_ammo), 3);
	*str = ft_strjoinf(*str, " ", 1);
	save_card(player, fd, str);
}

void	save_status(t_player *player, t_mesh cu, int fd, char **str)
{
	*str = ft_strjoinf(*str, ft_ftoa(player->hitbox.kinetic), 3);
	*str = ft_strjoinf(*str, " ", 1);
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
	*str = ft_strjoinf(*str, " 1.0 ", 1);
	*str = ft_strjoinf(*str, ft_itoa(player->hp), 3);
	*str = ft_strjoinf(*str, " ", 1);
	*str = ft_strjoinf(*str, ft_itoa(player->armor), 3);
	*str = ft_strjoinf(*str, " ", 1);
	*str = ft_strjoinf(*str, ft_itoa(player->fuel), 3);
	*str = ft_strjoinf(*str, " ", 1);
	save_ammo(player, fd, str);
}

void	save_player_pos(t_player *player, t_mesh current, int fd)
{
	char	*str;

	if (!(str = ft_strdup("player: Player ")))
		error_exit(-70, "ft_strdup failed.");
	str = ft_strjoinf(str, ft_ftoa(current.pos.x), 3);
	str = ft_strjoinf(str, " ", 1);
	str = ft_strjoinf(str, ft_ftoa(current.pos.y), 3);
	str = ft_strjoinf(str, " ", 1);
	str = ft_strjoinf(str, ft_ftoa(current.pos.z), 3);
	str = ft_strjoinf(str, " ", 1);
	str = ft_strjoinf(str, ft_ftoa(current.size.x), 3);
	str = ft_strjoinf(str, " ", 1);
	str = ft_strjoinf(str, ft_ftoa(current.size.y), 3);
	str = ft_strjoinf(str, " ", 1);
	str = ft_strjoinf(str, ft_ftoa(current.size.z), 3);
	str = ft_strjoinf(str, " ", 1);
	str = ft_strjoinf(str, "NULL ", 1);
	save_status(player, current, fd, &str);
	ft_strdel(&str);
}

void	save_player(t_engine *engine, int fd)
{
	t_mesh	current;
	int		i;

	i = 0;
	while (i < engine->physic_engine->mesh_list->size)
	{
		current = t_mesh_list_at(engine->physic_engine->mesh_list, i);
		if (current.primitive == -1 && (current.is_visible
							|| !current.no_hitbox))
		{
			save_player_pos(engine->user_engine->player, current, fd);
			break ;
		}
		i++;
	}
}
