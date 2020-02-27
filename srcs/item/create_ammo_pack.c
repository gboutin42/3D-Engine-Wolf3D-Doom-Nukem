/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ammo_pack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:14:14 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_item		create_ammo_pack(int type, char *str)
{
	static int	num = 1;
	t_item		item;

	item.name = str;
	num++;
	if (type == 1)
		item.pf = refill_pistol;
	else if (type == 2)
		item.pf = refill_ar;
	else if (type == 3)
		item.pf = refill_rifle;
	else if (type == 4)
		item.pf = refill_shotgun;
	else if (type == 5)
		item.pf = refill_rpg;
	return (item);
}
