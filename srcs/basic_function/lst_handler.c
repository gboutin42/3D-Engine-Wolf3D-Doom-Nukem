/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:43:45 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:43:47 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_del_cont(void *content, size_t size)
{
	if (content != NULL)
	{
		ft_memdel((void**)&content);
		size = 0;
	}
}

void	ft_lstdelone(t_list_fd **alst, void (*del)(void*, size_t))
{
	if (alst)
	{
		(*del)((*alst)->rest, (*alst)->fd);
		ft_memdel((void**)alst);
	}
}

void	ft_lstadd(t_list_fd **alst, t_list_fd *new)
{
	if (alst && new)
	{
		new->next = *alst;
		*alst = new;
	}
}

void	ft_lstdel(t_list_fd **alst, void (*del)(void *, size_t))
{
	t_list_fd		*next;

	while (*alst)
	{
		next = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = next;
	}
}
