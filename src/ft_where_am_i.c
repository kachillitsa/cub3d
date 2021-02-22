/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_where_am_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 00:20:36 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/26 18:20:22 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_ur_n_sprites(int *x, int *y)
{
	if (g_sumup.map[*y][*x] == 'S' || g_sumup.map[*y][*x] == 'W' \
		|| g_sumup.map[*y][*x] == 'N' || g_sumup.map[*y][*x] == 'E')
	{
		g_sumup.map[*y][*x] == 'N' ? g_ur.ur_va = 0.0f : 0;
		g_sumup.map[*y][*x] == 'S' ? g_ur.ur_va = 3.14f : 0;
		g_sumup.map[*y][*x] == 'W' ? g_ur.ur_va = 1.7f : 0;
		g_sumup.map[*y][*x] == 'E' ? g_ur.ur_va = -1.7f : 0;
		g_ur.ur_x = *x + 0.5f;
		g_ur.ur_y = *y + 0.5f;
		g_sumup.map[*y][*x] = ' ';
	}
	else if (g_sumup.map[*y][*x] >= 'a')
	{
		g_sprite[g_sumup.map[*y][*x] - 'a'].isprite_y = *y;
		g_sprite[g_sumup.map[*y][*x] - 'a'].isprite_x = *x;
	}
}

void	ft_where_am_i(int y, int x0)
{
	int	x;

	while (y >= 0)
	{
		x = x0;
		while (x >= 0)
		{
			ft_ur_n_sprites(&x, &y);
			x--;
		}
		y--;
	}
}
