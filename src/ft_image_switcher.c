/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image_switcher.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 00:28:18 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/26 14:37:27 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_image_switcher(void)
{
	static int	buf_num;

	ft_draw_everything();
	if (buf_num == 0)
	{
		mlx_put_image_to_window(g_proj.mlx, g_proj.mlx_win, \
			g_proj.win_buf0.ptr, 0, 0);
		g_proj.win_buf.ptr = g_proj.win_buf1.ptr;
		g_proj.win_buf.data = g_proj.win_buf1.data;
		buf_num = 1;
	}
	else
	{
		mlx_put_image_to_window(g_proj.mlx, g_proj.mlx_win, \
			g_proj.win_buf1.ptr, 0, 0);
		g_proj.win_buf.ptr = g_proj.win_buf0.ptr;
		g_proj.win_buf.data = g_proj.win_buf0.data;
		buf_num = 0;
	}
	return (1);
}
