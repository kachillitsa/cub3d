/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_col_ceiling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 23:20:06 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/29 20:39:22 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_col_ceiling(void)
{
	static int	x;
	static int	y_col;

	x = 0;
	while (x < g_proj.scr_wth)
	{
		y_col = 0;
		while (y_col <= g_sumup.ceil_dn[x])
		{
			g_proj.win_buf.data[y_col * g_proj.scr_wth + x] = \
				g_proj.iceilling_col;
			y_col++;
		}
		x++;
	}
}
