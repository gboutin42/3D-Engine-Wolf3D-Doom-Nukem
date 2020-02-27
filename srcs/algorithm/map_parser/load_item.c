/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_item.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:41:00 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:41:03 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_item			new_item(t_mesh mesh)
{
	t_item		item;

	item.name = NULL;
	if (ft_strcmp(mesh.name, "Ammo_Pack") == '_')
		item = create_ammo_pack(mesh.hp * -1, mesh.name);
	else if (ft_strcmp(mesh.name, "Health_Pack") == '_')
		item = create_health_pack(mesh.name);
	else if (ft_strcmp(mesh.name, "Armor_Pack") == '_')
		item = create_armor_pack(mesh.name);
	else if (ft_strcmp(mesh.name, "Jet_Pack") == '_')
		item = create_jet_pack(mesh.name);
	else if (ft_strcmp(mesh.name, "Card") == '_')
		item = create_color_card(mesh.hp * -1);
	return (item);
}

t_item_list		*load_items(t_mesh_list *meshs)
{
	t_item_list	*result;
	t_item		item;
	int			i;

	i = 0;
	result = initialize_t_item_list();
	while (i < meshs->size)
	{
		if (t_mesh_list_at(meshs, i).collectible == 1)
		{
			item = new_item(t_mesh_list_at(meshs, i));
			t_item_list_push_back(result, item);
		}
		i++;
	}
	return (result);
}
