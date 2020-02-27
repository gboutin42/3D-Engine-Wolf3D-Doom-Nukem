/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_item.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:32:33 by spuisais          #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		heal(t_player *player)
{
	int to_heal;

	to_heal = 20;
	if (player->hp < 100)
	{
		while (player->hp < 100 && to_heal-- > 0)
			player->hp += 1;
		return (BOOL_TRUE);
	}
	return (BOOL_FALSE);
}

int		protect(t_player *player)
{
	int to_protect;

	to_protect = 20;
	if (player->armor < 100)
	{
		while (player->armor < 100 && to_protect-- > 0)
			player->armor += 1;
		return (BOOL_TRUE);
	}
	return (BOOL_FALSE);
}

t_item	create_health_pack(char *str)
{
	static int	num = 1;
	t_item		item;

	item.name = str;
	num++;
	item.pf = heal;
	return (item);
}

t_item	create_armor_pack(char *str)
{
	static int	num = 1;
	t_item		item;

	item.name = str;
	num++;
	item.pf = protect;
	return (item);
}
