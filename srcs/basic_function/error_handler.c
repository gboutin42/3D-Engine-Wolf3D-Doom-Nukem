/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:42:29 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:42:31 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	error_exit(int error, char *message)
{
	ft_putstr("Error ");
	ft_putnbr(error);
	ft_putstr(" : ");
	ft_putstr(message);
	endl();
	exit(error);
}
