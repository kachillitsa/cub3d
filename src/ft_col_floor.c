/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_col_floor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 23:53:30 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/29 20:42:11 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_col_floor(void)
{
	static int	x;
	static int	y_col;

	x = 0;
	while (x < g_proj.scr_wth)
	{
		y_col = g_proj.scr_hght_m1;
		while (y_col >= 0)
		{
			g_proj.win_buf.data[y_col * g_proj.scr_wth + x] = \
				g_proj.ifloor_col;
			y_col--;
		}
		x++;
	}
}
