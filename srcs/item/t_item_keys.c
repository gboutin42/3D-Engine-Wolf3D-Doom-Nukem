/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_item_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:42:14 by spuisais          #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		red_card(t_player *player)
{
	player->red_card = 1;
	return (BOOL_TRUE);
}

int		blue_card(t_player *player)
{
	player->blue_card = 1;
	return (BOOL_TRUE);
}

int		green_card(t_player *player)
{
	player->green_card = 1;
	return (BOOL_TRUE);
}

t_item	create_color_card(int type)
{
	t_item		item;

	item.name = NULL;
	if (type == 1)
	{
		item.name = "Card_red";
		item.pf = red_card;
	}
	else if (type == 2)
	{
		item.name = "Card_blue";
		item.pf = blue_card;
	}
	else if (type == 3)
	{
		item.name = "Card_green";
		item.pf = green_card;
	}
	return (item);
}
