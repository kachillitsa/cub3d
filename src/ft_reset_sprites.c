/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_sprites.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:23:36 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/26 17:06:13 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_reset_sprites(void)
{
	static int i;
	static int iheart;

	iheart = 0;
	i = 0;
	while (i < g_sumup.sp_num)
	{
		iheart += g_sprite[i].iheart;
		g_sprite[i].ifirst_rayx = -401;
		i++;
	}
}
