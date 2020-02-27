/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_item_jetpack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:39:48 by spuisais          #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		jetpack(t_player *player)
{
	int	to_fill;

	to_fill = 50;
	if (player->fuel < 300)
	{
		while (player->fuel < 300 && to_fill-- > 0)
			player->fuel += 1;
		return (BOOL_TRUE);
	}
	return (BOOL_FALSE);
}

t_item	create_jet_pack(char *str)
{
	static int	num = 1;
	t_item		item;

	item.name = str;
	num++;
	item.pf = jetpack;
	return (item);
}
