/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compression.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:45:26 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:45:26 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	tar_ressources(void)
{
	char *command;

	if (!(command = ft_strdup("tar -jcf ressources.tar.bz2 ressources && \
							rm -rf ressources")))
		error_exit(-70, "ft_strdup failed");
	system(command);
	ft_strdel(&command);
}

void	untar_ressources(void)
{
	char	*command;

	if (!(command = ft_strdup("tar -jxf ressources.tar.bz2")))
		error_exit(-70, "ft_strdup failed");
	if (system(command) == 256)
		ft_putstr("Ressources already untarred, proceeding.\n");
	ft_strdel(&command);
	if (!(command = ft_strdup("rm -rf ressources.tar.bz2")))
		error_exit(-70, "ft_strdup failed");
	system(command);
	ft_strdel(&command);
}
